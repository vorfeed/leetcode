#include "head.h"

/**
 https://leetcode.com/problems/next-permutation

 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 The replacement must be in-place, do not allocate extra memory.

 Here are some examples.
 Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
   1,2,3 → 1,3,2
   3,2,1 → 1,2,3
   1,1,5 → 1,5,1
 */

// refer to: https://discuss.leetcode.com/topic/8508/9-lines-of-c-code-with-comments
// modified

/**
 * 排列的下一个数
 */
/**
 * 1）首先从后往前找出第一个按递增序排列的数字的位置（两个递增序数字前一个的位置）
 * 2）将该位置后面的数字全部倒置顺序（因为后面的数字全部按倒序排列，转成顺序排）
 * 3）在后面的数字里找出一个比指定位置上的数大的最小的数
 * 4）交换这个数和指定位置上的数
 */

// 16ms, beats 7.11%
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if (nums.empty()) {
      return;
    }
    int i;
    for (i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        break;
      }
    }
    reverse(begin(nums) + (i + 1), end(nums));
    if (i == -1) {
      return;
    }
    auto ite = upper_bound(begin(nums) + i + 1, end(nums), nums[i]);
    swap(nums[i], *ite);
  }
};
