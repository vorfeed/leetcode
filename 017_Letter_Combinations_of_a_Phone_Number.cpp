#include "head.h"

/**
 https://leetcode.com/problems/letter-combinations-of-a-phone-number

 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 Note:
   Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

// refer to: https://discuss.leetcode.com/topic/13160/8-line-backtracking-function-c-solution
// modified

/**
 * 给定一个整数，打印出所有每一位数字对应的手机按键上的字符的组合字符串
 */
/**
 * 回溯法
 */

// 0ms, beats 79.58%
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return ret_;
    }
    digits_ = digits;
    characters_ = {
      {},
      {},
      { 'a', 'b', 'c' },
      { 'd', 'e', 'f' },
      { 'g', 'h', 'i' },
      { 'j', 'k', 'l' },
      { 'm', 'n', 'o' },
      { 'p', 'q', 'r', 's' },
      { 't', 'u', 'v' },
      { 'w', 'x', 'y', 'z' }
    };
    string current;
    backtracking(current, 0);
    return ret_;
  }

private:
  void backtracking(string& current, size_t index) {
    if (index == digits_.size()) {
      ret_.emplace_back(current);
      return;
    }
    for (char c : characters_[digits_[index] - '0']) {
      current.push_back(c);
      backtracking(current, index + 1);
      current.pop_back();
    }
  }

  vector<string> ret_;
  string digits_;
  vector<vector<char>> characters_;
};
