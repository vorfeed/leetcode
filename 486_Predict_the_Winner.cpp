#include "head.h"

/**
 https://leetcode.com/problems/predict-the-winner

 Given an array of scores that are non-negative integers.
 Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

 Given an array of scores, predict whether player 1 is the winner.
 You can assume each player plays to maximize his score.

 Example 1:
   Input: [1, 5, 2]
   Output: False
   Explanation: Initially, player 1 can choose between 1 and 2.
   If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
   So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
   Hence, player 1 will never be the winner and you need to return False.

 Example 2:
   Input: [1, 5, 233, 7]
   Output: True
   Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
   Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

 Note:
   1 <= length of the array <= 20.
   Any scores in the given array are non-negative integers and will not exceed 10,000,000.
   If the scores of both players are equal, then player 1 is still the winner.
 */

// refer to: https://discuss.leetcode.com/topic/76830/java-9-lines-dp-solution-easy-to-understand-with-improvement-to-o-n-space-complexity
// modified

/**
 * 给定一个非负整数数组，两个人依次从数组两端取一个数字，取走的数字不能再取，判断第一个取的人能否获胜
 */
/**
 * dp[i][j]表示第一个人从i到j取的数字和最多能比第二个人多多少，下标从0开始
 *   i>j：没有意义
 *   i==j：第一个人直接取走
 *   i<j：dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])，分两种情况：
 *     第一个人取走nums[i]时，剩下的i+1到j里第二个人能比第一个人多取走dp[i + 1][j]，那么第一个人能比第二个人多取走(nums[i] - dp[i + 1][j]
 *     同理，当第一个人取走nums[j]时，他能比第二个人多取走nums[j] - dp[i][j - 1]；取两者的最大值
 */

// 3ms, beats 37.92%
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    for (int i = 0; i < nums.size(); ++i) {
      dp[i][i] = nums[i];
    }
    for (int len = 1; len < nums.size(); ++len) {
      for (int i = 0; i < nums.size() - len; ++i) {
        int j = i + len;
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    return dp[0][nums.size() - 1] >= 0;
  }
};
