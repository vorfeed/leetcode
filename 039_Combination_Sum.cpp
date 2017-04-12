#include "head.h"

/**
 https://leetcode.com/problems/combination-sum

 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.

 Note:
   All numbers (including target) will be positive integers.
   The solution set must not contain duplicate combinations.
 For example, given candidate set [2, 3, 6, 7] and target 7,
 A solution set is:
 [
   [7],
   [2, 2, 3]
 ]
 */

// refer to:
// modified

/**
 * 给定一个正整数数组，找出里面所有各个数的组合（可重复）使其和为特定值
 */
/**
 * 回溯法，因每个数字都可重用，每次回溯时的起始下标还是为上一轮递归时的下标
 */

// 23ms, beats 38.57%
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    candidates_ = move(candidates);
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
      combination_.push_back(candidates_[i]);
      combinationSum(target - candidates_[i], i);
      combination_.pop_back();
    }
  }

  vector<int> candidates_;
  vector<int> combination_;
  vector<vector<int>> results_;
};
