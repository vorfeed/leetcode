#include "head.h"

/**
 https://leetcode.com/problems/combination-sum-iii

 Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

 Example 1:
   Input: k = 3, n = 7
   Output:
     [[1,2,4]]

 Example 2:
   Input: k = 3, n = 9
   Output:
     [[1,2,6], [1,3,5], [2,3,4]]
 */

// refer to:
// modified

/**
 * 在1-9的数字中找出k个数，使其和为n
 */
/**
 *
 */

// 0ms, beats 39.63%
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    combinationSum(n, 1, k);
    return results_;
  }

private:
  void combinationSum(int target, int begin, int left) {
    if (!left) {
      if (!target) {
        results_.push_back(combination_);
      }
      return;
    }
    for (size_t i = begin; i != 10 && target > 0; ++i) {
      combination_.push_back(i);
      combinationSum(target - i, i + 1, left - 1);
      combination_.pop_back();
    }
  }

  vector<int> combination_;
  vector<vector<int>> results_;
};
