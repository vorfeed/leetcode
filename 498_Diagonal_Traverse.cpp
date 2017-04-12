#include "head.h"

/**
 https://leetcode.com/problems/diagonal-traverse

 Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 Example:
   Input:
   [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
   ]
   Output:  [1,2,4,7,5,3,6,8,9]
   Explanation:

 Note:
   The total number of elements of the given matrix will not exceed 10,000.
 */

// refer to: https://discuss.leetcode.com/topic/77865/concise-java-solution
// modified

/**
 * 对角蛇形遍历MxN矩阵
 */
/**
 * 每次沿对角前进方向遍历，遇到边界时调整下标，同时调转方向
 */

// 82ms, beats 83.95%
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return {};
    }
    int row_size = matrix.size(), column_size = matrix.front().size();
    int size = matrix.size() * matrix.front().size();
    vector<int> ret(size);
    int row = 0, column = 0, direction = 0;
    vector<vector<int>> directions = { {-1, 1}, {1, -1} };
    for (int i = 0; i < size; ++i) {
      ret[i] = matrix[row][column];
      row += directions[direction][0];
      column += directions[direction][1];
      if (row >= row_size) {
        row = row_size - 1;
        column += 2;
        direction = 1 - direction;
      }
      if (column >= column_size) {
        column = column_size - 1;
        row += 2;
        direction = 1 - direction;
      }
      if (row < 0) {
        row = 0;
        direction = 1 - direction;
      }
      if (column < 0) {
        column = 0;
        direction = 1 - direction;
      }
    }
    return ret;
  }
};
