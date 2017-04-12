#include "head.h"

/**
 https://leetcode.com/problems/zuma-game

 Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W).
 You also have several balls in your hand.
 Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place).
 Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

 Find the minimal balls you have to insert to remove all the balls on the table.
 If you cannot remove all the balls, output -1.

 Examples:
   Input: "WRRBBW", "RB"
   Output: -1
   Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

   Input: "WWRRBBWW", "WRBRW"
   Output: 2
   Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

   Input:"G", "GGGGG"
   Output: 2
   Explanation: G -> G[G] -> GG[G] -> empty

   Input: "RBYYBBRRB", "YRBGB"
   Output: 3
   Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty

 Note:
   You may assume that the initial row of balls on the table won¡¯t have any 3 or more consecutive balls with the same color.
   The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
   The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
   Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
 */

// refer to: https://discuss.leetcode.com/topic/79820/short-java-solution-beats-98
// modified

/**
 * 给定一个字符串，里面包含5种字符表示5种颜色的球
 * 手上有另一个包含5种颜色球的字符串，取出将这个字符串里的几个颜色（可无序，不一定要全用完）依次插入到前一个字符串中，如果插入后和边上的球连续3个颜色相同就消掉
 * 求把前一个字符串全消除最少需要几次插入操作
 */
/**
 * 先将字符串中连续出现3次的相同字符删除
 * 顺序遍历字符串，对每一段连续的相同字符
 * 判断手上的字符串里能否拿出足够多的该字符，使插入后能达到3个，将该段连续字符删除，同时手上的字符串里也要清除已使用数量的该字符
 * 按这个过程递归调用删除该段连续字符后的新字符串，得到最终需要的操作次数
 * 顺序处理每一段连续的相同字符串后，取每种情况下的操作情况最小值
 */

// 3ms, beats 77.83%
class Solution {
public:
  int findMinStep(string board, string hand) {
    for (const char c : hand) {
      ++hand_count_[c - 'A'];
    }
    int rs = helper(board + "#");
    return rs == kMaxCount ? -1 : rs;
  }

private:
  static constexpr int kMaxCount = 6;

  int helper(string s) {
    s = removeConsecutive(s);
    if (s == "#") {
      return 0;
    }
    int rs = kMaxCount, need = 0;
    for (int i = 0, j = 0; j < s.length(); ++j) {
      if (s[j] == s[i]) {
        continue;
      }
      need = 3 - (j - i);
      if (hand_count_[s[i] - 'A'] >= need) {
        hand_count_[s[i]  - 'A'] -= need;
        rs = min(rs, need + helper(s.substr(0, i) + s.substr(j)));
        hand_count_[s[i]  - 'A'] += need;
      }
      i = j;
    }
    return rs;
  }

  string removeConsecutive(string board) {
    for (int i = 0, j = 0; j < board.length(); ++j) {
        if (board[j] == board[i]) {
          continue;
        }
        if (j - i >= 3) {
          return removeConsecutive(board.substr(0, i) + board.substr(j));
        }
        i = j;
    }
    return board;
  }

  array<int, 32> hand_count_;
};
