#include "head.h"

/**
 https://leetcode.com/problems/increasing-subsequences

 Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

 Example:
   Input: [4, 6, 7, 7]
   Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

 Note:
   The length of the given array will not exceed 15.
   The range of integer in the given array is [-100,100].
   The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
 */

// refer to:
// modified

/**
 * 给定一个整数数组，找出其中所有不重复的递增子数组
 */
/**
 * 使用回溯法，每次固定一个数后对后面的数进行递归选取，判断符合条件的放入结果集中
 * 回溯法进行中，当判断到某个数加进来不符合要求时，不用再考虑不把这个数加进来时对后面的数继续递归的情况
 * 因为本层递归的循环中已经包含了跳过这个数继续递归后面数的情况，能一定程度剪枝
 * 在判断重复子数组时，考虑到只有当两个子数组的每一位数字都相同时才被认为相同，可以只判断在前一个数已选定的情况下保证当前数字不会选为相同的情况，因此只需在每一层递归时单独维护一张对单个数字的去重表
 */

// 232ms, beats 92.55%
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    nums_.swap(nums);
    current_.reserve(nums_.size());
    findSubsequences(0);
    nums_.swap(nums);
    return { ret_.begin(), ret_.end() };
  }

private:
  void findSubsequences(int index) {
    if (current_.size() >= 2) {
      ret_.emplace_back(current_);
    }
    unordered_set<int> dedup;
    for (int i = index; i < nums_.size(); ++i) {
      if (!dedup.emplace(nums_[i]).second) {
        continue;
      }
      if (current_.empty() || current_.back() <= nums_[i]) {
        current_.emplace_back(nums_[i]);
        findSubsequences(i + 1);
        current_.pop_back();
      }
    }
  }

  vector<int> nums_;
  deque<vector<int>> ret_;
  vector<int> current_;
};
