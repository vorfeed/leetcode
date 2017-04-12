#include "head.h"

/**
 https://leetcode.com/problems/combination-sum-ii

 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 Each number in C may only be used once in the combination.

 Note:
   All numbers (including target) will be positive integers.
   The solution set must not contain duplicate combinations.
 For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 A solution set is:
 [
   [1, 7],
   [1, 2, 5],
   [2, 6],
   [1, 1, 6]
 ]
 */

// refer to:
// modified

/**
 * 给定一个正整数数组，找出里面所有各个数的组合（不能重复）使其和为特定值
 */
/**
 *
 */

// 12ms, beats 64.27%
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    candidates_ = move(candidates);
    sort(candidates_.begin(), candidates_.end());
    combinationSum(target, 0);
    candidates = move(candidates_);
    return results_;
  }

private:
  void combinationSum(int target, int begin) {
    if (!target) {
      results_.push_back(combination_);
      return;
    }
    for (size_t i = begin; i < candidates_.size() && target >= candidates_[i]; ++i) {
      if (i == begin || candidates_[i] != candidates_[i - 1]) {
        combination_.push_back(candidates_[i]);
        combinationSum(target - candidates_[i], i + 1);
        combination_.pop_back();
      }
    }
  }

  vector<int> candidates_;
  vector<int> combination_;
  vector<vector<int>> results_;
};
