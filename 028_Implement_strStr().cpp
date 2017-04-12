#include "head.h"

/**
 https://leetcode.com/problems/implement-strstr

 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

// refer to: https://discuss.leetcode.com/topic/15569/explained-4ms-easy-c-solution
// modified

/**
 * 实现strstr()函数的功能
 */
/**
 *
 */

// 6ms, beats 30.20%
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    if (needle.length() > haystack.length()) {
      return -1;
    }
    size_t last_begin = haystack.length() - needle.length() + 1;
    for (size_t i = 0; i < last_begin; ++i) {
      size_t j = 0;
      for (; j < needle.length(); ++j) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == needle.length()) {
        return i;
      }
    }
    return -1;
  }
};
