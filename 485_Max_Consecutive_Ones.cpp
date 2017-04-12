#include "head.h"

/**
 https://leetcode.com/problems/max-consecutive-ones

 Given a binary array, find the maximum number of consecutive 1s in this array.

 Example 1:
   Input: [1,1,0,1,1,1]
   Output: 3
   Explanation: The first two digits or the last three digits are consecutive 1s.
   The maximum number of consecutive 1s is 3.

 Note:
   The input array will only contain 0 and 1.
   The length of input array is a positive integer and will not exceed 10,000
 */

// refer to:
// modified

/**
 * 给定一个由0和1构成的数组，找出其中最大连续出现1的个数
 */
/**
 *
 */

// 36ms, beats 74.82%
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, max_count = 0;
    for (int num : nums) {
      if (num & 1) {
        ++count;
        if (count > max_count) {
          max_count = count;
        }
      } else {
        count = 0;
      }
    }
    return max_count;
  }
};
