#include "head.h"

/**
 https://leetcode.com/problems/longest-valid-parentheses

 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has length = 2.

 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

// refer to: https://discuss.leetcode.com/topic/2289/my-o-n-solution-using-a-stack
// modified

/**
 * 最长的有效括号匹配对数量
 */
/**
 * 用一个栈记录每一次遇到不匹配时记录其下标
 * 遍历每一个字符，如果是左括号则入栈，右括号如果能和栈顶匹配则栈顶出栈，其他遇到不匹配的情况将下标入栈
 * 遍历完成后，栈中各相邻下标间的最大差值即为所求最大匹配数量
 */

// 9ms, beats 39.50%
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<size_t> st;
    for (size_t i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (!st.empty()) {
          if (s[st.top()] == '(') {
            st.pop();
          } else {
            st.push(i);
          }
        } else {
          st.push(i);
        }
      }
    }
    size_t longest = 0;
    if (st.empty()) {
      longest = s.length();
    } else {
      size_t a = s.length(), b = 0;
      while (!st.empty()) {
        b = st.top();
        st.pop();
        longest = max(longest, a - b - 1);
        a = b;
      }
      longest = max(longest, a);
    }
    return longest;
  }
};
