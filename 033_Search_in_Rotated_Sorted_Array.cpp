#include "head.h"

/**
 https://leetcode.com/problems/search-in-rotated-sorted-array

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 You are given a target value to search.
 If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.
 */

// refer to: https://discuss.leetcode.com/topic/16580/java-ac-solution-using-once-binary-search
// modified

/**
 * 旋转排序数组里查找一个数
 */
/**
 *
 */

/*
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
      int mid = (start + end) >> 1;
      if (nums[start] == nums[end]) {
        return mid;
      }
      if (nums[start] <= nums[mid]) {
        if (nums[start] <= target && target < nums[mid]) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }
      if (nums[mid] <= nums[end]) {
        if (nums[mid] < target && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return -1;
  }
};
*/

// 3ms, beats 65.27%
class Solution2 {
public:
  int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
      int mid = start + (( end - start) >> 1);
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[start] <= nums[mid]) {
        if (nums[start] <= target && target < nums[mid]) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return -1;
  }
};
