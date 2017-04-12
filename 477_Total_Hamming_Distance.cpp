#include "head.h"

/**
 https://leetcode.com/problems/total-hamming-distance

 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 Now your job is to find the total Hamming distance between all pairs of the given numbers.

 Example:
   Input: 4, 14, 2
   Output: 6
   Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
   showing the four bits relevant in this case). So the answer will be:
   HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

 Note:
   Elements of the given array are in the range of 0 to 10^9
   Length of the array will not exceed 10^4.
 */

// refer to: https://discuss.leetcode.com/topic/72092/java-o-n-time-o-1-space
// modified

/**
 * 给定一组数，找出所有数两两之间二进制表示的汉明距离（两个相同长度的数对应不同bit的数量）的总和
 */
/**
 * 对32位数字的每一位分别计算距离，如n个数，某一位上k个数有设置，n-k个数没有设置，该位对应的汉明距离为k*(n-k)
 * 把每一位上的汉明距离相加即为总的汉明距离
 */

// 83ms, beats 31.83%
class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < 32; ++i) {
      int bit_set = 0;
      for (int num : nums) {
        bit_set += (num >> i) & 1;
      }
      total += bit_set * (nums.size() - bit_set);
    }
    return total;
  }
};
