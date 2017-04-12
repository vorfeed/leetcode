#include "head.h"

/**
 https://leetcode.com/problems/maximal-rectangle

 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 For example, given the following matrix:
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 6.
 */

// refer to:
// modified

/**
 * 二维矩阵由0和1组成，找出其中由1组成的面积最大的矩形
 */
/**
 * dp算法：
 *   height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';
 *   height(i,j) = 0, if matrix[i][j]=='0'
 *     height表示当前节点（包含）上方连续1出现的个数
 *   left(i,j) = max(left(i-1,j), cur_left)
 *   right(i,j) = min(right(i-1,j), cur_right)
 *     left、right表示在当前height下，包含当前节点的左右边界使矩形面积最大的可取值；cur_left、cur_right表示当前这一行上包含当前节点的一维矩形左右两端的值
 *   矩形面积：max((right[i,j]-left[i,j])*height[i,j])
 */

// 6ms, beats 95.99%
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return 0;
    }
    vector<int> height(matrix.front().size(), 0),
        left(matrix.front().size(), 0),
        right(matrix.front().size(), matrix.front().size());
    int maximum = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      int cur_left = 0, cur_right = matrix.front().size();
      for (int j = 0; j < matrix.front().size(); ++j) {
        height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
      }
      for (int j = 0; j < matrix.front().size(); ++j) {
        left[j] = matrix[i][j] == '1' ? max(left[j], cur_left) : (cur_left = j + 1, 0);
      }
      for (int j = matrix.front().size() - 1; j >= 0; --j) {
        right[j] = matrix[i][j] == '1' ? min(right[j], cur_right) :
            (cur_right = j, matrix.front().size());
      }
      for (int j = 0; j < matrix.front().size(); ++j) {
        maximum = max(maximum, (right[j] - left[j]) * height[j]);
      }
    }
    return maximum;
  }
};

// 15ms, beats 38.94%
class Solution2 {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return 0;
    }
    vector<int> height(matrix.front().size() + 1, 0);
    int maximum = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      stack<int> s;
      for (int j = 0; j < matrix.front().size() + 1; ++j) {
        if (j < matrix.front().size()) {
          height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
        }
        if (s.empty() || height[s.top()] <= height[j]) {
          s.push(j);
          continue;
        }
        while (!s.empty() && height[j] < height[s.top()]) {
          int top = s.top();
          s.pop();
          int area = height[top] * (s.empty() ? j : (j - s.top() - 1));
          maximum = max(maximum, area);
        }
        s.push(j);
      }
    }
    return maximum;
  }
};
