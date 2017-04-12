#include "head.h"

/**
 https://leetcode.com/problems/unique-paths-ii

 Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids.
 How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 The total number of unique paths is 2.
 */

// refer to:
// modified

/**
 * 同上，网格中含有障碍物
 */
/**
 * 建立dp数组
 * 当前点不为障碍物时同上，P[i][j]=P[i-1][j]+P[i][j-1]；为障碍物时P[i][j]=0
 * 由于边界值可能包含障碍物，需要对边界值特殊处理，有障碍物的地方后面都到达不了
 */

// 3ms, beats 23.91%
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid.front().size();
    vector<vector<int>> path(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      if (obstacleGrid[i][0]) {
        break;
      }
      path[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
      if (obstacleGrid[0][j]) {
        break;
      }
      path[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!obstacleGrid[i][j]) {
          path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
      }
    }
    return path[m - 1][n - 1];
  }
};
