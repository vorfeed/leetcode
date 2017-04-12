#include "head.h"

/**
 https://leetcode.com/problems/valid-parentheses

 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

// refer to: https://discuss.leetcode.com/topic/13231/2ms-c-sloution
// modified

/**
 * 校验括号匹配
 */
/**
 *
 */

// 3ms, beats 3.68%
class Solution {
public:
  bool isValid(string s) {
    stack<char> last;
    for (char c : s) {
      switch(c) {
      case '{':
      case '[':
      case '(':
        last.push(c);
        break;
      case '}':
        if (last.empty() || last.top() != '{') {
          return false;
        }
        last.pop();
        break;
      case ']':
        if (last.empty() || last.top() != '[') {
          return false;
        }
        last.pop();
        break;
      case ')':
        if (last.empty() || last.top() != '(') {
          return false;
        }
        last.pop();
        break;
      default:
        break;
      }
    }
    return last.empty();
  }
};
