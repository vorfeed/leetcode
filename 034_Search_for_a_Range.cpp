#include "head.h"

/**
 https://leetcode.com/problems/search-for-a-range

 Given a sorted array of integers, find the starting and ending position of a given target value.
 Your algorithm's runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return [-1, -1].

 For example,
   Given [5, 7, 7, 8, 8, 10] and target value 8,
   return [3, 4].
 */

// refer to: https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation
// modified

/**
 * 有序数组中查找某个重复出现数的起止位置
 */
/**
 *
 */

// 9ms, beats 50.78%
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret(2, -1);
    if (nums.empty()) {
      return ret;
    }
    int start = 0, end = nums.size() - 1;
    while (start < end) {
      int mid = (start + end) >> 1;
      if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    if (nums[start] != target) {
      return ret;
    }
    ret[0] = start;
    start = 0, end = nums.size() - 1;
    while (start < end) {
      int mid = ((start + end) >> 1) + 1;
      if (nums[mid] > target) {
        end = mid - 1;
      } else {
        start = mid;
      }
    }
    ret[1] = end;
    return ret;
  }
};
