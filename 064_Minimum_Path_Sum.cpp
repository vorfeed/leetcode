#include "head.h"

/**
 https://leetcode.com/problems/minimum-path-sum

 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time.
 */

// refer to:
// modified

/**
 * m×n网格中，从左上角移到右下角的最小值路径（只能向右或向下移动）
 */
/**
 * 建立dp数组，记录当前点最小值，公式：P[i][j]=min(P[i-1][j], P[i][j-1])+grid[i][j]
 * 处理边界值，路径值只能前面值有关，P[i][0]=P[i-1][0]+grid[i][0]，P[0][j]=P[0][j-1]+grid[0][j]
 */

// 13ms, 16.94%
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid.front().size();
    vector<vector<int> > sum(m, vector<int>(n, grid.front().front()));
    for (int i = 1; i < m; ++i) {
      sum[i][0] = sum[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
      sum[0][j] = sum[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
      }
    }
    return sum[m - 1][n - 1];
  }
};
