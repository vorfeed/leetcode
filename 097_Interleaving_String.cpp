#include "head.h"

/**
 https://leetcode.com/problems/interleaving-string

 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

 For example,
   Given:
     s1 = "aabcc",
     s2 = "dbbca",
   When s3 = "aadbbcbcac", return true.
   When s3 = "aadbbbaccc", return false.
 */

// refer to:
// modified

/**
 * 判断字符串s3能否由s1和s2交织而成
 */
/**
 *
 */

// Time Limit Exceeded
/** Input:
 "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
 "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
 "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
 */
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }
    if (s3.empty()) {
      return true;
    }
    auto ite1 = s1.begin(), ite2 = s2.begin();
    for (auto ite3 = s3.begin(); ite3 != s3.end(); ++ite3) {
      if (ite1 == s1.end()) {
        return string(ite3, s3.end()) == string(ite2, s2.end());
      }
      if (ite2 == s2.end()) {
        return string(ite3, s3.end()) == string(ite1, s1.end());
      }
      bool b1 = *ite3 == *ite1, b2 = *ite3 == *ite2;
      if (b1 && b2) {
        return isInterleave(string(ite1 + 1, s1.end()), string(ite2, s2.end()), string(ite3 + 1, s3.end())) ||
            isInterleave(string(ite1, s1.end()), string(ite2 + 1, s2.end()), string(ite3 + 1, s3.end()));
      }
      if (b1) {
        ++ite1;
      } else if (b2) {
        ++ite2;
      } else {
        return false;
      }
    }
    return true;
  }
};
