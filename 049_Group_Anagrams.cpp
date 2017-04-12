#include "head.h"

/**
 https://leetcode.com/problems/anagrams

 Given an array of strings, group anagrams together.

 For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Return:
 [
   ["ate", "eat","tea"],
   ["nat","tan"],
   ["bat"]
 ]

 Note: All inputs will be in lower-case.
 */

// refer to:
// modified

/**
 * 给定一组字符串，将相同字符组成的字符串划分到一起
 */
/**
 * 用hash表来存储，将字符串按字符排序后作为key
 */

// 82ms, beats 25.83%
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, multiset<string>> checked;
    for (const string& str : strs) {
      string sorted_str(str);
      sort(sorted_str.begin(), sorted_str.end());
      checked[sorted_str].emplace(str);
    }
    vector<vector<string>> anagrams;
    for (auto strings : checked) {
      vector<string> anagram(strings.second.begin(), strings.second.end());
      anagrams.push_back(anagram);
    }
    return anagrams;
  }
};
