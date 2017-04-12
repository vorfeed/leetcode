#include "head.h"

/**
 https://leetcode.com/problems/rotate-image

 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).

 Follow up:
   Could you do this in-place?
 */

// refer to: https://discuss.leetcode.com/topic/6796/a-common-method-to-rotate-the-image
// modified

/**
 * n×n矩阵顺时针旋转90度
 */
/**
 * 先将矩阵每一行倒转，再将矩阵转置
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
 */
// 3ms, 31.18%
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i + 1; j < matrix[i].size(); ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
