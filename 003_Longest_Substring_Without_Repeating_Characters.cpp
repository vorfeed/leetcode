#include "head.h"

/**
 https://leetcode.com/problems/longest-substring-without-repeating-characters

 Given a string, find the length of the longest substring without repeating characters.

 Examples:
   Given "abcabcbb", the answer is "abc", which the length is 3.
   Given "bbbbb", the answer is "b", with the length of 1.
   Given "pwwkew", the answer is "wke", with the length of 3.
   Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

// refer to: https://leetcode.com/discuss/37957/accepted-solution-bitmask-record-position-letter-appears
// modified

/**
 * 字符串中找出没有重复字符的最长连续子串的长度
 */
/**
 * 用一个start记录当前维护的无重复字符的窗口的起始位置，用一个selected表记录当前窗口中出现的字符的下标
 * 遍历字符串中的每一个字符，如果该字符在selected表中的下标大于start，说明这个字符已经在窗口中出现过，此时将最长窗口长度更新为该字符串之前的窗口长度，并将start移到这个字符第一次出现的位置之后，确保新窗口中没有重复的字符
 */

// 16ms, beats 66.42%
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> selected(256, -1);
    int max_len = 0, start = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (selected[s[i]] >= start) {
        max_len = max(max_len, i - start);
        start = selected[s[i]] + 1;
      }
      selected[s[i]] = i;
    }
    return max(max_len, static_cast<int>(s.length()) - start);
  }
};
