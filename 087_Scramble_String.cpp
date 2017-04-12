#include "head.h"

/**
 https://leetcode.com/problems/scramble-string

 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

 Below is one possible representation of s1 = "great":
   great
   /    \
    gr    eat
   / \    /  \
  g   r  e   at
   / \
            a   t
 To scramble the string, we may choose any non-leaf node and swap its two children.

 For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
   rgeat
   /    \
    rg    eat
   / \    /  \
  r   g  e   at
   / \
            a   t
 We say that "rgeat" is a scrambled string of "great".

 Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
   rgtae
   /    \
    rg    tae
   / \    /  \
  r   g  ta  e
   / \
        t   a
 We say that "rgtae" is a scrambled string of "great".

 Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

// refer to:
// modified

/**
 * 判断两个字符串是否为Scramble（字符串分解为二叉树，倒转某个非叶子节点后的新字符串）
 */
/**
 * 将字符串分成两个子串，分别判断每个子串是否Scramble，递归这个过程
 */

// 89ms, beats 8.85%
class Solution {
public:
  bool isScramble(string s1, string s2) {
    bool ret = false;
    if (s1.empty()) {
      return true;
    }
    if (is_scramble_.count(s1 + s2)) {
      return is_scramble_[s1 + s2];
    }
    if (s1 == s2) {
      return is_scramble_[s1 + s2] = true;
    }
    for (int i = 1; i < s1.length() && !ret; ++i) {
      ret = ret
          || (isScramble(s1.substr(0, i), s2.substr(0, i))
              && isScramble(s1.substr(i, s1.length() - i), s2.substr(i, s1.length() - i)))
          || (isScramble(s1.substr(0, i), s2.substr(s1.length() - i, i))
              && isScramble(s1.substr(i, s1.length() - i), s2.substr(0, s1.length() - i)));
    }
    return is_scramble_[s1 + s2] = ret;
  }

private:
  unordered_map<string, bool> is_scramble_;
};
