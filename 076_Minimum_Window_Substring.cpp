#include "head.h"

/**
 https://leetcode.com/problems/minimum-window-substring

 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

 For example,
   S = "ADOBECODEBANC"
   T = "ABC"
   Minimum window is "BANC".

 Note:
   If there is no such window in S that covers all characters in T, return the empty string "".
   If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

// refer to:
// modified

/**
 * 在字符串S中，找出包含了所有字符串T中字符的最小窗口
 */
/**
 * 用一张表记录T中每个字符出现的次数（考虑有重复字符的情况）
 * 定义两个下标变量begin、end，分别表示处理过程中窗口的起止位置，处理时对end下标从头到尾开始遍历
 * 定义一个counter变量表示当前窗口中还有多少个T中的字符没有包含进来
 * 每遍历一个数字都对起始表里的数字计数-1，这样T中不存在的字符的计数始终为<=0
 * 当减一操作前表中对应字符的计数不为0时，说明这个字符在T中存在
 * 此时当前窗口新加入了一个T的字符，对counter减1操作
 * 当counter为0时，所有字符都包含在窗口中，当前窗口为符合要求的一个解，判断是否需要更新最小长度
 * 此时begin下标开始后移，对初始那张表中的字符统计+1
 * 如果当前表中的该字符的统计为0，因为窗口中已经包含了该字符，因此表之前必然做过-1操作，即表中该字符原来的统计数为正值，即为T中的字符
 * 此时一个T中的字符被从窗口中剔除，counter加1操作
 * counter不再为0，不满足最小窗口条件，继续对end下标进行遍历
 * 重复上面的过长，找出最小窗口
 */

// 9ms, beats 70.11%
class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> used(128, 0);
    for (char c : t) {
      ++used[c];
    }
    int counter = t.size();
    int begin = 0, end = 0;
    string min_str;
    while (end < s.size()) {
      if (used[s[end++]]-- > 0) {
        --counter;
      }
      while (counter == 0) {
        if (used[s[begin++]]++ == 0) {
          if (min_str.empty() || end - begin < min_str.length()) {
            min_str = s.substr(begin - 1, end - begin + 1);
          }
          ++counter;
        }
      }
    }
    return min_str;
  }
};
