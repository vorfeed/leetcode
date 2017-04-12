#include "head.h"

/**
 https://leetcode.com/problems/permutation-sequence

 The set [1,2,3,¡­,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,

 We get the following sequence (ie, for n = 3):
   "123"
   "132"
   "213"
   "231"
   "312"
   "321"
 Given n and k, return the kth permutation sequence.

 Note: Given n will be between 1 and 9 inclusive.
 */

// refer to: https://discuss.leetcode.com/topic/19181/0ms-c-12-line-concise-solution-no-recursion-no-helper-function
// modified

/**
 * 输出全排列中第k个序列
 */
/**
 * 先生成一个包含1-n这n个字符的dict数组，作为待选字符集
 * 再生成一个包含(n-1)!, (n-2)!, ..., 1!, 0!的fract数组，倒序排列，对应每个位置上选一个固定的字符后，都包含这么多种可能的排序
 * 从左往右遍历fract数组，用k去余fract当前值，商即为当前位置排到的字符，余数进入下一个位置的计算
 * 从dict中根据商取出对应位置的字符，同时把这个字符从dict中删除，这样下一次计算时商值会往后顺延
 * 重复这个过程
 */

// 3ms, beats 26.14%
class Solution {
public:
  string getPermutation(int n, int k) {
    string dict(n, 0);
    iota(dict.begin(), dict.end(), '1');
    vector<int> fract(n, 1);
    for (int idx = n - 3; idx >= 0; --idx) {
      fract[idx] = fract[idx + 1] * (n - 1 - idx);
    }
    --k;
    string ret(n, 0);
    for (int idx = 0; idx < n; ++idx) {
      int select = k / fract[idx];
      k %= fract[idx];
      ret[idx] = dict[select];
      dict.erase(next(dict.begin(), select));
    }
    return ret;
  }
};
