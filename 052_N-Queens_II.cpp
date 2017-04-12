#include "head.h"

/**
 https://leetcode.com/problems/n-queens-ii

 Follow up for N-Queens problem.

 Now, instead outputting board configurations, return the total number of distinct solutions.
 */

// refer to:
// modified

/**
 * n皇后不同解的个数
 */
/**
 * 用bitmap来记录每列、135度角、45度角是否已设置过，45和135度角需要用到row和column两个下标，因此bitmap的长度为2n
 */

// 3ms, beats 69.28%
class Solution {
public:
  int totalNQueens(int n) {
    n_ = n;
    columns_.resize(n);
    diagonal45s_.resize(n * 2);
    diagonal135s_.resize(n * 2);
    count_ = 0;
    backTracking(0);
    return count_;
  }

private:
  void backTracking(int row) {
    if(row == n_) {
      ++count_;
    }
    for(int col = 0; col < n_; ++col) {
      int diagonal45 = col + row;
      int diagonal135 = n_ - row + col;
      if(columns_[col] || diagonal45s_[diagonal45] || diagonal135s_[diagonal135]) {
        continue;
      }
      columns_[col] = diagonal45s_[diagonal45] = diagonal135s_[diagonal135] = true;
      backTracking(row + 1);
      columns_[col] = diagonal45s_[diagonal45] = diagonal135s_[diagonal135] = false;
    }
  }

  int n_;
  vector<bool> columns_, diagonal45s_, diagonal135s_;
  int count_;
};
