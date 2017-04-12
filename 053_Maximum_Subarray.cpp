#include "head.h"

/**
 https://leetcode.com/problems/maximum-subarray

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

// refer to:
// modified

/**
 * 连续子数组的最大和
 */
/**
 *
 */

// 9ms, beats 31.47%
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ret = nums.front(), maximum = 0;
    for(int num : nums){
        ret = max(maximum += num, ret);
        maximum = max(maximum, 0);
    }
    return ret;
  }
};
