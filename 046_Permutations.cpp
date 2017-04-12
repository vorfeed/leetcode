#include "head.h"

/**
 https://leetcode.com/problems/permutations

 Given a collection of distinct numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [
   [1,2,3],
   [1,3,2],
   [2,1,3],
   [2,3,1],
   [3,1,2],
   [3,2,1]
 ]
 */

// refer to:
// modified

/**
 * 全排列
 */
/**
 *
 */

// 13ms, 42.01%
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    nums_ = move(nums);
    backTracking(0);
    nums = move(nums_);
    return ret_;
  }

private:
  void backTracking(int begin) {
    if (begin == nums_.size()) {
      ret_.push_back(nums_);
      return;
    }
    for (int i = begin; i < nums_.size(); ++i) {
      swap(nums_[begin], nums_[i]);
      backTracking(begin + 1);
      swap(nums_[begin], nums_[i]);
    }
  }

  vector<int> nums_;
  vector<vector<int>> ret_;
};
