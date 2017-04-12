#include "head.h"

/**
 https://leetcode.com/problems/first-missing-positive

 Given an unsorted integer array, find the first missing positive integer.

 For example,
   Given [1,2,0] return 3,
   and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.
 */

// refer to:
// modified

/**
 * 给定一个无序整数数组，找出第一个缺失的正整数
 */
/**
 * 遍历每一个下标
 * 如果当前数字的值-1不和下标相等，就将当前数字和当前值-1下标对应的数交换
 * 重复这个过程，直到下标与值匹配或者出现非法数字
 * 再从头遍历数组，找出第一个不匹配的位置
 */

// 3ms, 18.20%
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};
