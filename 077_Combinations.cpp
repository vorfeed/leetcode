#include "head.h"

/**
 https://leetcode.com/problems/combinations

 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 For example,
 If n = 4 and k = 2, a solution is:
 [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
 ]
 */

// refer to:
// modified

/**
 * 组合
 */
/**
 * 回溯法，用一个栈记录已选取的数字
 * 从1到n遍历每一个数字，下一次迭代时的起始数字加1，栈中数字后面的都比前面的大
 * 取到k个数时记录并回溯
 * 如果当前数字后面剩余的数字个数加起来不足以组成k个，可提前结束对后面数字的回溯
 */

// 79ms, beats 83.39%
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    n_ = n;
    backTracking(1, k);
    return ret_;
  }

private:
  void backTracking(int begin, int k) {
    if (!k) {
      ret_.push_back(current_);
      return;
    }
    for (int i = begin; i <= n_ -k + 1; ++i) {
      current_.push_back(i);
      backTracking(i + 1, k - 1);
      current_.pop_back();
    }
  }

  int n_;
  vector<vector<int>> ret_;
  vector<int> current_;
};
