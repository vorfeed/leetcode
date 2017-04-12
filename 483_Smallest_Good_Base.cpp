#include "head.h"

/**
 https://leetcode.com/problems/smallest-good-base

 For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.
 Now given a string representing n, you should return the smallest good base of n in string format.

 Example 1:
   Input: "13"
   Output: "3"
   Explanation: 13 base 3 is 111.

 Example 2:
   Input: "4681"
   Output: "8"
   Explanation: 4681 base 8 is 11111.

 Example 3:
   Input: "1000000000000000000"
   Output: "999999999999999999"
   Explanation: 1000000000000000000 base 999999999999999999 is 11.

 Note:
   The range of n is [3, 10^18].
   The string representing n is always valid and will not have leading zeros.
 */

// refer to: https://discuss.leetcode.com/topic/76347/3ms-ac-c-long-long-int-binary-search/2
// modified

/**
 * 把一个十进制整数n转成k进制，使得每位都为1，求最小的k
 */
/**
 * 从最长的全为1的字符串开始找起，每次判断能否找到符合要求的k，找不到则1的个数减1继续找
 * 对于整数num，它能转换成的最长1的个数为log(num)/log(2)+1
 * 对于1个数为d，k进制的情况，num = 1 + k + k^2 + ... + k^(d-1) = (k^d - 1) / (k-1) > k^(d-1)，k的取值只有一种可能：k = pow(num,1.0/(d-1))
 */

// 3ms, beats 48.62%
class Solution {
public:
  string smallestGoodBase(string n) {
    long num = stol(n);
    int maxlen = log(num) / log(2) + 1;
    for (int d = maxlen; d >= 3; --d) {
      long k = pow(num, 1.0 / (d - 1)), sum = 1, cur = 1;
      for (int i = 1; i < d; ++i) {
        sum += (cur *= k);
      }
      if (sum == num) {
        return to_string(k);
      }
    }
    return to_string(num - 1);
  }
};
