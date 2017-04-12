#include "head.h"

/**
 https://leetcode.com/problems/substring-with-concatenation-of-all-words

 You are given a string, s, and a list of words, words, that are all of the same length.
 Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

 For example, given:
 s: "barfoothefoobarman"
 words: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).
 */

// refer to: https://discuss.leetcode.com/topic/17943/naive-c-solution-using-two-unordered_map-about-20-lines
// modified

/**
 * 给定一个字符串和一组单词，每个单词长度相同，找出一个子字符串包含全部的单词，没有重叠且每个单词只出现一次
 */
/**
 * 从每一个字符开始遍历，取待匹配的单词总长度个字符，按单词长度逐个切分子字符串
 * 用hash表记录每一段中每个单词出现的次数，如果出现不在单词列表里或者超过单词列表里的数量可提前中断，继续下一次迭代
 */

// 482ms, beats 60.36%
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> counts;
    for (const string& word : words) {
      ++counts[word];
    }
    int n = s.length(), num = words.size(), len = words[0].length();
    vector<int> indexes;
    for (int i = 0; i < n - num * len + 1; ++i) {
      unordered_map<string, int> seen;
      int j = 0;
      for (; j < num; ++j) {
        string word = s.substr(i + j * len, len);
        if (counts.find(word) != counts.end()) {
          ++seen[word];
          if (seen[word] > counts[word]) {
            break;
          }
        } else {
          break;
        }
      }
      if (j == num) {
        indexes.push_back(i);
      }
    }
    return indexes;
  }
};
