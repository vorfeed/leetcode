#include "head.h"

/**
 https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
   Given sorted array nums = [1,1,1,2,2,3],

 Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 It doesn't matter what you leave beyond the new length.
 */

// refer to: https://discuss.leetcode.com/topic/17180/3-6-easy-lines-c-java-python-ruby
// modified

/**
 * 排序数组中删除重复的数字，允许相同的数字最多保留2个，返回去重后的数组长度
 */
/**
 * 用一个索引i表示当前数组更新到的位置
 * 从第3个数开始每次与他前面两格位置的数相比，如果相同说明这个数出现超过了2次，需要被去掉
 * 否则将这个需要保留的数移到更新索引的位置上，索引后移
 */

// 22ms, beats 12.54%
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int num : nums) {
      if (i < 2 || num > nums[i - 2]) {
        nums[i++] = num;
      }
    }
    return i;
  }
};
