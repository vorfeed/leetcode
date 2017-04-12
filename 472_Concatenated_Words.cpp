#include "head.h"
#include "util/trie.h"

/**
 https://leetcode.com/problems/concatenated-words

 Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
 A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 Example:
   Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
   Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

 Explanation:
   "catsdogcats" can be concatenated by "cats", "dog" and "cats";
   "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
   "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

 Note:
   The number of elements of the given array will not exceed 10,000
   The length sum of elements in the given array will not exceed 600,000.
   All the input string will only include lower case letters.
   The returned elements order does not matter.
 */

// refer to:
// modified

/**
 * 给定一组单词，找出其中所有能由几个其他单词构成的单词
 */
/**
 * 将单词按长度从短到长排序，对每个单词做dp
 */

// 598 ms, beats 60.91%
class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(),
        [](const string& lhs, const string& rhs) {
      return lhs.length() < rhs.length();
    });
    words_.insert(words.begin(), words.end());
    vector<string> result;
    for (const string& word : words) {
      if (word.empty()) {
        continue;
      }
      words_.erase(word);
      if (dfs(word)) {
        result.emplace_back(word);
      }
      words_.insert(word);
      visited_[word] = true;
    }
    return result;
  }
private:
  bool dfs(const string& word) {
    if (visited_.count(word)) {
      return visited_[word];
    }
    for (size_t i = 1; i < word.size(); ++i) {
      if (words_.count(word.substr(0, i)) && dfs(word.substr(i))) {
        return visited_[word] = true;
      }
    }
    return visited_[word] = word.empty();
  }
  unordered_map<string, bool> visited_;
  unordered_set<string> words_;
};
