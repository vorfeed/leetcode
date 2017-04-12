#include "head.h"

/**
 https://leetcode.com/problems/permutations-ii

 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

 For example,
 [1,1,2] have the following unique permutations:
 [
   [1,1,2],
   [1,2,1],
   [2,1,1]
 ]
 */

// refer to:
// modified

/**
 * 带重复数的全排列
 */
/**
 * 对数字排序，用一张表记录每个位置的数字的使用情况
 * 每一个重复数字必须在他前一个数字已被使用的情况下才能使用，保证重复数字之间的有序性，这样就不会出现重叠的情况
 */

// 26ms, 63.01%
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    nums_ = move(nums);
    if (nums_.empty()) {
      return ret_;
    }
    used_.resize(nums_.size());
    sort(nums_.begin(), nums_.end());
    backTracking();
    nums = move(nums_);
    return ret_;
  }

private:
  void backTracking() {
    if(current_.size() == nums_.size()) {
      ret_.emplace_back(current_);
      return;
    }
    for (int i = 0; i < nums_.size(); ++i) {
      if (used_[i] ||
          (i > 0 && nums_[i - 1] == nums_[i] && !used_[i - 1])) {
        continue;
      }
      used_[i] = true;
      current_.emplace_back(nums_[i]);
      backTracking();
      used_[i] = false;
      current_.pop_back();
    }
  }

  vector<int> nums_, current_;
  vector<vector<int>> ret_;
  vector<bool> used_;
};
