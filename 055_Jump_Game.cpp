#include "head.h"

/**
 https://leetcode.com/problems/jump-game

 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.

 For example:
   A = [2,3,1,1,4], return true.
   A = [3,2,1,0,4], return false.
 */

// refer to:
// modified

/**
 * 非负整数数组表示你在该位置可以往后跳的最大步长，求能否到达最后一个节点
 */
/**
 * 遍历每一个数，记录能跳到的最远位置
 * 遍历过程中发现当前位置已经超过了最远位置，则跳不到
 * 如果能跳到的最远位置已经超过最后一个数位置，可以提前返回
 */

// 13ms, beats 40.57%
class Solution {
public:
  bool canJump(vector<int>& nums) {
    for (int reach = 0, i = 0; i < nums.size() && i <= reach; ++i) {
        reach = max(i + nums[i], reach);
        if (reach >= nums.size() - 1) {
          return true;
        }
    }
    return false;
  }
};
