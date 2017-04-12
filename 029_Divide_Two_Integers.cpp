#include "head.h"

/**
 https://leetcode.com/problems/divide-two-integers

 Divide two integers without using multiplication, division and mod operator.

 If it is overflow, return MAX_INT.
 */

// refer to: https://discuss.leetcode.com/topic/15568/detailed-explained-8ms-c-solution
// modified

/**
 * 两个整数相除，不能使用乘、除、取余操作
 */
/**
 *
 */

// 26ms, beats 19.79%
class Solution {
public:
  int divide(int dividend, int divisor) {
    if (!divisor || (dividend == numeric_limits<int>::min() && divisor == -1)) {
      return numeric_limits<int>::max();
    }
    bool positive = ((dividend < 0) ^ (divisor < 0)) ? false : true;
    long long abs_dividend = labs(dividend);
    long long abs_divisor = labs(divisor);
    int ret = 0;
    while (abs_dividend >= abs_divisor) {
      long long temp = abs_divisor, multiple = 1;
      while (abs_dividend >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
      }
      abs_dividend -= temp;
      ret += multiple;
    }
    return positive ? ret : -ret;
  }
};
