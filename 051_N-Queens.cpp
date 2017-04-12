#include "head.h"

/**
 https://leetcode.com/problems/n-queens

 The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space ret_pectively.

 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 [
   [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

   ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
 ]
 */

// refer to:
// modified

/**
 * n皇后
 */
/**
 * 回溯法，按列进行遍历，每次在该列检验某行能否放入Queue，检验通过到下一行继续这种过程遍历
 * 检验时需要判断每一列、45度角、135度角是否冲突，行在插入时保证
 */

// 6ms, beats 67.92%
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    n_ = n;
    queens_.resize(n, string(n, '.'));
    backTracking(0);
    return ret_;
  }

private:
  void backTracking(int row) {
    if (row == n_) {
      ret_.push_back(queens_);
      return;
    }
    for (int col = 0; col < n_; ++col) {
      if (isValid(row, col)) {
        queens_[row][col] = 'Q';
        backTracking(row + 1);
        queens_[row][col] = '.';
      }
    }
  }

  bool isValid(int row, int col) {
    for (int i = 0; i < row; ++i) {
      if (queens_[i][col] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (queens_[i][j] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n_; --i, ++j) {
      if (queens_[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

  int n_;
  vector<vector<string>> ret_;
  vector<string> queens_;
};
