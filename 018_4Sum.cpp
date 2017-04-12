#include "head.h"

/**
 https://leetcode.com/problems/4sum

 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note: The solution set must not contain duplicate quadruplets.

 For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 A solution set is:
 [
   [-1,  0, 0, 1],
   [-2, -1, 1, 2],
   [-2,  0, 0, 2]
 ]
 */

// refer to: https://discuss.leetcode.com/topic/9712/4sum-c-solution-with-explanation-and-comparison-with-3sum-problem-easy-to-understand
// modified

/**
 * 数组中找出4个数，使其和为给定值
 */
/**
 * （类似2Sum、3Sum）
 */

// 29ms, beats 71.87%
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (auto ite = nums.begin(); ite < nums.end(); ++ite) {
      if (ite != nums.begin() && *(ite - 1) == *ite) {
        continue;
      }
      for (auto ite2 = ite + 1; ite2 < nums.end(); ++ite2) {
        if (ite2 != ite + 1 && *(ite2 - 1) == *ite2) {
          continue;
        }
        int target_left = target - *ite - *ite2;
        decltype(ite2) begin = ite2 + 1, end = nums.end() - 1;
        while (begin < end) {
          int sum = *begin + *end;
          if (target_left == sum) {
            ret.emplace_back(vector<int> { *ite, *ite2, *begin, *end });
            while (begin < end && *begin == *++begin);
            while (begin < end && *end == *--end);
          } else {
            sum > target_left ? --end : ++begin;
          }
        }
      }
    }
    return ret;
  }
};
