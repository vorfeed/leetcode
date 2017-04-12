#include "head.h"

/**
 https://leetcode.com/problems/merge-sorted-array

 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

 Note:
   You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
   The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

// refer to:
// modified

/**
 * 将一个有序数组并入另一个有序数组
 */
/**
 * 两个数组都从后面开始merge
 * 如果merge完后第二个数组有剩余，全部复制到第一个数组最前面
 */

// 6ms, beats 14.93%
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index1 = m - 1, index2 = n - 1, index = m + n - 1;
    while (index1 >= 0 && index2 >= 0) {
      nums1[index--] = nums1[index1] > nums2[index2] ?
          nums1[index1--] : nums2[index2--];
    }
    if (index2 >= 0) {
      copy(nums2.begin(), nums2.begin() + index2 + 1, nums1.begin());
    }
  }
};
