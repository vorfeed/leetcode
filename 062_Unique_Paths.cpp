#include "head.h"

/**
 https://leetcode.com/problems/unique-paths

 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 The robot can only move either down or right at any point in time.
 The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 How many possible unique paths are there?

 Above is a 3 x 7 grid. How many possible unique paths are there?

 Note: m and n will be at most 100.
 */

// refer to:
// modified

/**
 * mxn的网格中，从左上角到右下角有多少条不同的路径（只能往右和往下）
 */
/**
 * 建立dp数组，第i行第j列的不同路径数P[i][j]=P[i-1][j]+P[i][j-1]
 * 边界值P[i][0]=P[0][j]=1，因为只有从上往下或者从左往右一条路径
 */

// 0ms, beats 30.87%
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> path(m, vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        path[i][j] = path[i - 1][j] + path[i][j - 1];
      }
    }
    return path[m - 1][n - 1];
  }
};
