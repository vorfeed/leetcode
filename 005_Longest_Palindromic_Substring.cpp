#include "head.h"

/**
 https://leetcode.com/problems/longest-palindromic-substring

 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 Example:
   Input: "babad"
   Output: "bab"
   Note: "aba" is also a valid answer.

 Example:
   Input: "cbbd"
   Output: "bb"
 */

// refer to: https://discuss.leetcode.com/topic/12187/simple-c-solution-8ms-13-lines
// modified

/**
 * 最长回文子字符串
 */
/**
 * 依次遍历每一个字符，向两边延伸判断是否为回文
 * 延伸开始时可以跳过连续的相同字符
 * 当剩余未遍历的字符数小于已计算得到的最大长度的一半时，可提前结束遍历
 */

// 6ms, beats 78.54%
class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty()) {
      return "";
    }
    if (s.size() == 1) {
      return s;
    }
    int min_start = 0, max_len = 1;
    for (size_t i = 0; i < s.size();) {
      if (s.size() - i <= max_len >> 1) {
        break;
      }
      int j = i, k = i;
      while (k < s.size() - 1 && s[k + 1] == s[k]) {
        ++k;
      }
      i = k + 1;
      while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
        ++k;
        --j;
      }
      int new_len = k - j + 1;
      if (new_len > max_len) {
        min_start = j;
        max_len = new_len;
      }
    }
    return s.substr(min_start, max_len);
  }
};
