#include "head.h"

/**
 https://leetcode.com/problems/subsets

 Given a set of distinct integers, nums, return all possible subsets.

 Note: The solution set must not contain duplicate subsets.

 For example,
 If nums = [1,2,3], a solution is:
 [
   [3],
   [1],
   [2],
   [1,2,3],
   [1,3],
   [2,3],
   [1,2],
   []
 ]
 */

// refer to: https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation
// modified

/**
 * 给定一个不重复的整数数组，返回所有子数组
 */
/**
 * 总共有2^n个子数组，使用位运算来计算每个位置上的子数组包含哪些数。考虑{1 , 2 , 3 }的情况：
 *   0) 0 0 0  -> Dont take 3 , Dont take 2 , Dont take 1 = { } 
 *   1) 0 0 1  -> Dont take 3 , Dont take 2 ,   take 1       =  {1 } 
 *   2) 0 1 0  -> Dont take 3 ,    take 2       , Dont take 1 = { 2 } 
 *   3) 0 1 1  -> Dont take 3 ,    take 2       ,      take 1    = { 1 , 2 } 
 *   4) 1 0 0  ->    take 3      , Dont take 2  , Dont take 1 = { 3 } 
 *   5) 1 0 1  ->    take 3      , Dont take 2  ,     take 1     = { 1 , 3 } 
 *   6) 1 1 0  ->    take 3      ,    take 2       , Dont take 1 = { 2 , 3 } 
 *   7) 1 1 1  ->    take 3     ,      take 2     ,      take 1     = { 1 , 2 , 3 } 
 * 即第一轮循环先将1加入到第0位为1的位置上，第2轮循环将2加入到第1位为1的位置上，第3论循环将3加入到第2位为1的位置上
 */

// 6ms, beats 22.26%
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int num = pow(2, nums.size());
    vector<vector<int>> ret(num, vector<int>());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < num; ++j) {
        if ((j >> i) & 1) {
          ret[j].push_back(nums[i]);
        }
      }
    }
    return ret;
  }
};
