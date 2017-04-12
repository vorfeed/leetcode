#include "head.h"

/**
 https://leetcode.com/problems/search-in-rotated-sorted-array-ii

 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Write a function to determine if a given target is in the array.
 The array may contain duplicates.
 */

// refer to:
// modified

/**
 * 旋转数组中查找某个数，可以重复
 */
/**
 * 整体思路跟不存在重复时类似
 * 由于存在重复，循环过程中可能会出现nums[left] == nums[mid]这种情况，需要单独处理
 * 考虑[3 1 2 3 3 3 3]这种情况，此时nums[left] == nums[mid] == nums[right] == 3，此时如果target不是3，无法确定走哪一段，因此需要特殊处理
 * 将left和right都向中间移一步
 */

// 6ms, beats 30.78%
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] == target) {
        return true;
      }
      if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
        ++left;
        --right;
      } else if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] <= nums[right]) {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return false;
  }
};
