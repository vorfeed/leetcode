#include "head.h"

/**
 https://leetcode.com/problems/text-justification

 Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 Extra spaces between words should be distributed as evenly as possible.
 If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 For the last line of text, it should be left justified and no extra space is inserted between words.

 For example,
   words: ["This", "is", "an", "example", "of", "text", "justification."]
   L: 16.

   Return the formatted lines as:
   [
     "This    is    an",
     "example  of text",
     "justification.  "
   ]

 Note: Each word is guaranteed not to exceed L in length.
 */

// refer to: https://discuss.leetcode.com/topic/4189/share-my-concise-c-solution-less-than-20-lines
// modified

/**
 * 给定一组字符串和一个长度L，取尽可能多的字符串，在他们之间插入空格，使每行L个字符
 */
/**
 * 先依次找出k个字符串，使他们总长度加上k-1个空格的长度为小于L的最大可行值
 * 再将不足L长度的空格数平摊到各个字符串之间
 */

// 3ms, beats 1.36%
class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    for (int i = 0, k, l; i < words.size(); i += k) {
      for (k = l = 0; i + k < words.size() && l + words[i + k].size() <= maxWidth - k; ++k) {
        l += words[i + k].size();
      }
      string str = words[i];
      for (int j = 0; j < k - 1; ++j) {
        if (i + k >= words.size()) {
          str += " ";
        } else {
          str += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
        }
        str += words[i + j + 1];
      }
      str += string(maxWidth - str.size(), ' ');
      ret.push_back(str);
    }
    return ret;
  }
};
