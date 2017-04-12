#include "head.h"

/**
 https://leetcode.com/problems/sqrtx

 Implement int sqrt(int x).

 Compute and return the square root of x.
 */

// refer to:
// modified

/**
 * 开根号
 */
/**
 * 二分查找法
 */

// 6ms, beats 13.99%
class Solution {
public:
  int mySqrt(int x) {
    if (!x) {
      return 0;
    }
    int left = 1, right = numeric_limits<int>::max();
    while (true) {
      int mid = left + ((right - left) >> 1);
      if (mid > x / mid) {
        right = mid - 1;
      } else {
        if (mid + 1 > x / (mid + 1)) {
          return mid;
        }
        left = mid + 1;
      }
    }
    return left;
  }
};
