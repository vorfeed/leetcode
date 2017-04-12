#include "head.h"

/**
 https://leetcode.com/problems/trapping-rain-water

 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 For example,
   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 In this case, 6 units of rain water (blue section) are being trapped.
 Thanks Marcos for contributing this image!
 */

// refer to:
// modified

/**
 * 柱形图中能盛多少水
 */
/**
 * 用两个指针从头尾开始向中间遍历，遍历过程中记录maxleft和maxright
 * 每轮迭代判断左右指针值的大小，如果左指针的值比右指针小，说明中间的部分肯定能盛最高高度为左边值大小的水位，处理左指针部分
 * 同样如果右指针的值小，处理右边部分
 * 判断左指针后面一块柱形的高度，如果比左指针小，最大盛水量就加上两条柱形的高度差值
 * 如果比左指针大，说明中间部分能盛更高高度的水，更新maxleft值
 * 做指针后移
 */

// 16ms, 4.86%
class Solution {
public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] >= maxleft) {
          maxleft = height[left];
        } else {
          res += maxleft - height[left];
        }
        ++left;
      } else {
        if (height[right] >= maxright) {
          maxright = height[right];
        } else {
          res += maxright - height[right];
        }
        --right;
      }
    }
    return res;
  }
};
