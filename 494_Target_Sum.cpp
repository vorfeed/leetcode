#include "head.h"

/**
 https://leetcode.com/problems/target-sum

 You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
 Now you have 2 symbols + and -.
 For each integer, you should choose one from + and - as its new symbol.
 Find out how many ways to assign symbols to make sum of integers equal to target S.

 Example 1:
   Input: nums is [1, 1, 1, 1, 1], S is 3.
   Output: 5
   Explanation:
     -1+1+1+1+1 = 3
     +1-1+1+1+1 = 3
     +1+1-1+1+1 = 3
     +1+1+1-1+1 = 3
     +1+1+1+1-1 = 3
     There are 5 ways to assign symbols to make the sum of nums be target 3.

 Note:
   The length of the given array is positive and will not exceed 20.
   The sum of elements in the given array will not exceed 1000.
   Your output answer is guaranteed to be fitted in a 32-bit integer.
 */

// refer to: https://discuss.leetcode.com/topic/76243/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation
// modified

/**
 * 给定一个非负正整数数组，对他们进行加减操作使其和为给定值，输出所有可能的种树
 */
/**
 * 在每个数字被赋予正负后和为给定值的情况下，将所有正数即为集合P，负数为集合N，sum(P) - sum(N) = target即为满足条件的公式
 * 对这个公式进行扩展sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)，即2 * sum(P) = target + sum(nums)，得到sum(P) = (target + sum(nums)) / 2，也就是求一个子数组集合
 * 使其和为新的target：(target + sum(nums)) / 2，同时target + sum(nums)必须为偶数时才有解
 */

// 13ms, beats 70.38%
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < S || ((S + sum) & 1)) {
      return 0;
    }
    int sub_target = (S + sum) >> 1;
    vector<int> dp(sub_target + 1, 0);
    dp[0] = 1;
    for (int n : nums) {
      for (int i = sub_target; i >= n; --i) {
        dp[i] += dp[i - n];
      }
    }
    return dp[sub_target];
  }
};
