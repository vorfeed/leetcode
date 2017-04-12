#include "head.h"

/**
 https://leetcode.com/problems/longest-common-prefix

 Write a function to find the longest common prefix string amongst an array of strings.
 */

// refer to: https://discuss.leetcode.com/topic/27913/sorted-the-array-java-solution-2-ms
// modified

/**
 * 一组字符串的最长公共前缀
 */
/**
 * 所有字符串按字符大小排序，第一个和最后一个字符串的最长公共前缀即为所求
 */

// 6ms, beats 19.10%
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    sort(strs.begin(), strs.end());
    const string& first = strs.front();
    const string& last = strs.back();
    size_t len = min(first.length(), last.length());
    size_t i = 0;
    for (; i < len; ++i) {
      if (first[i] != last[i]) {
        break;
      }
    }
    return first.substr(0, i);
  }
};
