#include "head.h"

/**
 https://leetcode.com/problems/generate-parentheses

 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:
 [
   "((()))",
   "(()())",
   "(())()",
   "()(())",
   "()()()"
 ]
 */

// refer to:
// modified

/**
 * 打印所有圆括号匹配的组合
 */
/**
 *
 */

// 3ms, beats 15.78%
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    backtracking("", n, 0);
    return ret_;
  }

private:
  void backtracking(const string& str, int left, int right){
      if(!left && !right) {
        ret_.emplace_back(str);
        return;
    }
    if (right > 0) {
      backtracking(str + ")", left, right - 1);
    }
    if (left > 0) {
      backtracking(str + "(", left - 1, right + 1);
    }
  }

  vector<string> ret_;
};
