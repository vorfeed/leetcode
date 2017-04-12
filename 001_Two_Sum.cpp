#include "head.h"

/**
 https://leetcode.com/problems/two-sum

 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 You may assume that each input would have exactly one solution.

 Example:
   Given nums = [2, 7, 11, 15], target = 9,
   Because nums[0] + nums[1] = 2 + 7 = 9,
   return [0, 1].

 UPDATE (2016/2/13):
   The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */

/**
 * 数组中找出两个数使其和为给定值
 */
/**
 * 使用hash表，遍历数组
 * 每取到一个数字就在hash表中查找是否存在加起来和为给定值的数，没有就将当前数放入hash表中
 * 时间O(n)，空间O(n)
 */

// 12ms, beat 92.91%
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> checked;
    for (int i = 0; i < nums.size(); ++i) {
      if (checked.count(target - nums[i])) {
        return { checked[target - nums[i]], i };
      }
      checked.emplace(nums[i], i);
    }
    return {};
  }
};
