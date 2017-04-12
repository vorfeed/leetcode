#include "head.h"

/**
 https://leetcode.com/problems/next-greater-element-i

 You are given two arrays (without duplicates) nums1 and nums2 where nums1¡¯s elements are subset of nums2.
 Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
 If it does not exist, output -1 for this number.

 Example 1:
   Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
   Output: [-1,3,-1]
   Explanation:
     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
     For number 1 in the first array, the next greater number for it in the second array is 3.
     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

 Example 2:
   Input: nums1 = [2,4], nums2 = [1,2,3,4].
   Output: [3,-1]
   Explanation:
     For number 2 in the first array, the next greater number for it in the second array is 3.
     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

 Note:
   All elements in nums1 and nums2 are unique.
   The length of both nums1 and nums2 would not exceed 1000.
 */

// refer to: https://discuss.leetcode.com/topic/77916/java-10-lines-linear-time-complexity-o-n-with-explanation
// modified

/**
 * 给定一个不重复的整数数组nums2和它的一个子数组nums1，都无序，求nums1中每个数在nums2中出现位置的下一个数
 */
/**
 * 遍历nums2，用一个栈记录所有递减形式的数
 * 每当新遍历一个数时，判断如果比栈顶值小，压入栈
 * 如果比栈顶值大，说明当前数就是栈顶数的Next Greater Element，把对应关系写入map
 * 处理完nums2后，遍历nums1，在map中找每个数的Next Greater Element，找不到就设为-1
 */

// 13ms, beats 42.11%
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    stack<int> s;
    unordered_map<int, int> m;
    for (int num : nums) {
      while (!s.empty() && s.top() < num) {
        m[s.top()] = num;
        s.pop();
      }
      s.push(num);
    }
    vector<int> ret;
    for (int n : findNums) {
      ret.push_back(m.count(n) ? m[n] : -1);
    }
    return ret;
  }
};
