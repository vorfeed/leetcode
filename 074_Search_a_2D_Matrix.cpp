#include "head.h"

/**
 https://leetcode.com/problems/search-a-2d-matrix

 Write an efficient algorithm that searches for a value in an m x n matrix.
 This matrix has the following properties:
   Integers in each row are sorted from left to right.
   The first integer of each row is greater than the last integer of the previous row.

 For example,
 Consider the following matrix:
 [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]
 Given target = 3, return true.
 */

// refer to:
// modified

/**
 * m×n矩阵（每行有序，下一行最小值大于上一行最大值）中查找一个数
 */
/**
 * 矩阵的二分查找，按照mxn的总长度做二分，mid/列数为行号，mid%列数为列号
 */

// 9ms, beats 39.54%
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
      return false;
    }
    int left = 0, right = matrix.size() * matrix.front().size() - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      int row = mid / matrix.front().size(), column = mid % matrix.front().size();
      if (matrix[row][column] < target) {
        left = mid + 1;
      } else if (matrix[row][column] > target) {
        right = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
