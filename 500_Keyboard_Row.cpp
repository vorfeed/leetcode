#include "head.h"

/**
 https://leetcode.com/problems/keyboard-row

 Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

 American keyboard

 Example 1:
   Input: ["Hello", "Alaska", "Dad", "Peace"]
   Output: ["Alaska", "Dad"]

 Note:
   You may use one character in the keyboard more than once.
   You may assume the input string will only contain letters of alphabet.
 */

// refer to: https://discuss.leetcode.com/topic/77761/c-solution
// modified

/**
 * 给定一组单词，输出所有能只通过键盘上一行按键打印出来的单词
 */
/**
 * 逐个单词逐个字符判断
 */

// 0ms, beats 73.87%
class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    const vector<unordered_set<char>> keyboard {
      { 'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p' },
      { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' },
      { 'z', 'x', 'c', 'v', 'b' ,'n', 'm' }
    };
    vector<string> ret;
    for (const string& word : words) {
      assert(!word.empty());
      char c = word.front();
      size_t row = 0;
      for (; row < keyboard.size(); ++row) {
        if (keyboard[row].count(tolower(c))) {
          break;
        }
      }
      assert(row < keyboard.size());
      ret.emplace_back(word);
      for (int i = 1; i < word.size(); ++i) {
        if (!keyboard[row].count(tolower(word[i]))) {
          ret.pop_back();
          break;
        }
      }
    }
    return ret;
  }
};
