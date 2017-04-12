#include "head.h"

/**
 https://leetcode.com/problems/set-matrix-zeroes

 Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 Do it in place.
 */

// refer to:
// modified

/**
 * 给定一个m×n矩阵，如果某一位置为0，设置整行整列都为0
 */
/**
 * 遍历矩阵，当某一格为0时将该行行首和该列列首都设为0
 * 由于第一行和第一列
 */

// 56ms, beats 57.77%
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int column0 = 1, m = matrix.size(), n = matrix.front().size();
    for (int i = 0; i < m; ++i) {
      if (!matrix[i][0]) {
        column0 = 0;
      }
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][j]) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j > 0; --j) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
      if (!column0) {
        matrix[i][0] = 0;
      }
    }
  }
};
