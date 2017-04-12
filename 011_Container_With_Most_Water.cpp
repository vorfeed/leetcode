#include "head.h"

/**
 https://leetcode.com/problems/container-with-most-water

 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 Note: You may not slant the container and n is at least 2.
 */

// refer to: https://discuss.leetcode.com/topic/16754/simple-and-fast-c-c-with-explanation
// modified

/**
 * 直角坐标系中n条平行y轴的垂线，求两条垂线跟x轴组成的容器的最大盛水量
 */
/**
 * 用头尾下标i,j从两边开始向中间遍历
 * 每次设置高度h为两边值中的较小值，最大盛水量为(j-i)*h，如果比前面维护的最大值大则更新
 * 将左下标往前移直到遇到的值大于h，同样右下标往左移直到遇到的值大于h
 * 因为j-i变小了，只有当两边的高度值都大于h时，新计算得到的盛水量才能可能比前面计算的大
 */

// 23ms, beats 41.39%
class Solution {
public:
  int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
      int h = min(height[i], height[j]);
      water = max(water, (j - i) * h);
      while (height[i] <= h && i < j) {
        i++;
      }
      while (height[j] <= h && i < j) {
        j--;
      }
    }
    return water;
  }
};
