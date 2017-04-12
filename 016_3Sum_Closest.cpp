#include "head.h"

/**
 https://leetcode.com/problems/3sum-closest

 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

// refer to: https://discuss.leetcode.com/topic/1978/a-n-2-solution-can-we-do-better
// modified

/**
 * 数组中找出3个数，使其和最接近某个值
 */
/**
 * （和3Sum类似）
 */

// 52ms, beats 7.05%
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    while (nums.size() <= 3) {
      return accumulate(nums.begin(), nums.end(), 0);
    }
    int answer = accumulate(nums.begin(), nums.begin() + 3, 0);
    for (auto ite = nums.begin(); ite < nums.end(); ++ite) {
      int target_left = target - *ite;
      decltype(ite) begin = ite + 1, end = nums.end() - 1;
      while (begin < end) {
        int sum = *begin + *end;
        if (abs(target_left - sum) < abs(target - answer)) {
          answer = sum + *ite;
          if (answer == target) {
            return answer;
          }
        }
        sum > target_left ? --end : ++begin;
      }
    }
    return answer;
  }
};
