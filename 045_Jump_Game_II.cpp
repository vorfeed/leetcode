#include "head.h"

/**
 https://leetcode.com/problems/jump-game-ii

 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.

 For example:
   Given array A = [2,3,1,1,4]

 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 Note:
   You can assume that you can always reach the last index.
 */

// refer to:
// modified

/**
 * 非负整数数组表示你在该位置可以往后跳的最大步长，求到达最后一个节点的最短跳跃次数
 */
/**
 * 每一次跳跃之后都会到一个新的节点上，计算从原位置到新位置之间每个节点能跳的最远的位置，这个最远位置即为下一次跳跃的最长距离
 * 按这个思路递归
 * 如果递归到达一次跳跃最大值边界时发现能到达的最远长度就是当前位置，说明无法到达终点，可提前结束
 */

// 13ms, 52.69%
class Solution {
public:
  int jump(vector<int>& nums) {
    int maxReach = nums[0];
    int edge = 0;
    int minstep = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (i > edge) {
        if (maxReach == edge) {
          return -1;
        }
        minstep += 1;
        edge = maxReach;
        if (edge > nums.size() - 1) {
          return minstep;
        }
      }
      maxReach = max(maxReach, nums[i] + i);
    }
    return minstep;
  }
};
