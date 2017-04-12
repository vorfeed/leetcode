#include "head.h"

/**
 https://leetcode.com/problems/reverse-pairs

 Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
 You need to return the number of important reverse pairs in the given array.

 Example1:
   Input: [1,3,2,3,1]
   Output: 2

 Example2:
   Input: [2,4,3,5,1]
   Output: 3

 Note:
   The length of the given array will not exceed 50,000.
   All the numbers in the input array are in the range of 32-bit integer.
 */

// refer to: https://discuss.leetcode.com/topic/78933/very-short-and-clear-mergesort-bst-java-solutions
// modified

/**
 * 给定一个正整数数组，统计其中所有满足下表I < j且nums[i] > 2*nums[j]的数对的个数
 */
/**
 * 使用归并排序的思路，对左右两段分段排序
 * 统计左右两段之间符合要求的数对的个数，加到总和中
 * 每次逐个对左边的数计算在右边段中的数对个数，由于右边段已排序，可以在右边段中维护一个符合要求的最大数的下标，通过下标的值直接得到
 * 递归调用这个过程
 */

// 475ms, beats 21.74%
class Solution {
public:
  int reversePairs(vector<int>& nums) {
    nums_.swap(nums);
    return mergeSort(0, nums_.size() - 1);
  }

private:
  int mergeSort(int start, int end) {
    if (start >= end) {
      return 0;
    }
    int mid = start + ((end - start) >> 1);
    int count = mergeSort(start, mid) + mergeSort(mid + 1, end);
    for (int i = start, j = mid + 1; i <= mid; ++i) {
      while (j <= end && nums_[i] / 2. > nums_[j]) {
        ++j;
      }
      count += j - (mid + 1);
    }
    sort(next(nums_.begin(), start), next(nums_.begin(), end + 1));
    return count;
  }

  vector<int> nums_;
};
