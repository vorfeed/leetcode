#include "head.h"

/**
 https://leetcode.com/problems/longest-increasing-path-in-a-matrix

 Given an integer matrix, find the length of the longest increasing path.
 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

 Example 1:
   nums = [
     [9,9,4],
     [6,6,8],
     [2,1,1]
   ]
   Return 4
   The longest increasing path is [1, 2, 6, 9].

 Example 2:
   nums = [
     [3,4,5],
     [3,2,6],
     [2,2,1]
   ]
   Return 4
   The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

// refer to:
// modified

/**
 * 在矩阵中找出一个最长递增序列，返回其长度
 */
/**
 *
 */

// 79ms, beat 45.43%
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return 0;
    }
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix.front().size(), 0));
    int maximum = 1;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix.front().size(); ++j) {
        maximum = max(maximum, dfs(matrix, visited, i, j));
      }
    }
    return maximum;
  }

private:
  int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j) {
    if (visited[i][j]) {
      return visited[i][j];
    }
    int maximum = 1;
    for (const pair<int, int>& dir : kDirection_) {
      int x = i + dir.second, y = j + dir.first;
      if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix.front().size() || matrix[x][y] <= matrix[i][j]) {
        continue;
      }
      maximum = max(maximum, 1 + dfs(matrix, visited, x, y));
    }
    visited[i][j] = maximum;
    return maximum;
  }

  const vector<pair<int, int>> kDirection_ { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
};
