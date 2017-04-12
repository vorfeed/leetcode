#include "head.h"

/**
 https://leetcode.com/problems/3sum

 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Note: The solution set must not contain duplicate triplets.

 For example, given array S = [-1, 0, 1, 2, -1, -4],
 A solution set is:
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]
 */

// refer to: https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments
// modified

/**
 * 数组中找出3个数，使其和为0
 */
/**
 * 先选定一个数，再按照2Sum的方式解决
 */

// 76ms, beats 14.02%
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    nums_ = move(nums);
    ret_.clear();
    sort(nums_.begin(), nums_.end());
    for (size_t i = 0; i < nums_.size(); ++i) {
      if (i > 0 && nums_[i] == nums_[i - 1]) {
        continue;
      }
      current_target_ = -nums_[i];
      twoSum(i + 1);
    }
    nums = move(nums_);
    return ret_;
  }

private:
  void twoSum(size_t start) {
    vector<int>::const_iterator begin = nums_.begin() + start, end = nums_.end() - 1;
    while (begin < end) {
      int sum = *begin + *end;
      if (sum < current_target_) {
        ++begin;
      } else if (sum > current_target_) {
        --end;
      } else {
        ret_.emplace_back(vector<int>({ -current_target_, *begin, *end }));
        while (begin < end && *begin == *(++begin));
        while (begin < end && *end == *(--end));
      }
    }
  }

  vector<int> nums_;
  int current_target_ { 0 };
  vector<vector<int>> ret_;
};
