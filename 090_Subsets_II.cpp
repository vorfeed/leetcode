#include "head.h"

/**
 https://leetcode.com/problems/subsets-ii

 Given a collection of integers that might contain duplicates, nums, return all possible subsets.

 Note: The solution set must not contain duplicate subsets.

 For example,
 If nums = [1,2,2], a solution is:
 [
   [2],
   [1],
   [1,2,2],
   [2,2],
   [1,2],
   []
 ]
 */

// refer to: https://discuss.leetcode.com/topic/39672/share-my-2ms-java-iteration-solution-very-simple-and-short
// modified

/**
 * 给定一个有重复的整数数组，返回所有子数组（不含重复）
 */
/**
 * 先将数组排序，构造result数组
 * 遍历数组中每一个数，将其逐个插入result里的每个数组中，构成新的子数组，加入到result数组中
 * 如果遇到相同的数，只有第一个数按这种方式处理，后面的重复数只插入到第一个数插入后的数组中，保证重复的数只有在第一个数已使用的情况下才被使用，不会出现重复的情况。
 */

// 9ms, beats 33.74%
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret(1, vector<int> {});
    int begin = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (!i || nums[i] != nums[i - 1]) {
        begin = 0;
      }
      int size = ret.size();
      for (int j = begin; j < size; ++j) {
        vector<int> current = ret[j];
        current.push_back(nums[i]);
        ret.emplace_back(move(current));
      }
      begin = size;
    }
    return ret;
  }
};
