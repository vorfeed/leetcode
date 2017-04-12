#include "head.h"

/**
 https://leetcode.com/problems/largest-rectangle-in-histogram

 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 The largest rectangle is shown in the shaded area, which has area = 10 unit.

 For example,
   Given heights = [2,1,5,6,2,3],
   return 10.
 */

// refer to:
// modified

/**
 * 直方图中找最大的矩形
 */
/**
 * 用一个栈来存矩形条的高度
 * 遍历直方图，当矩形条高度大于栈顶矩形条高度时，将当前下标入栈
 * 如果遇到当前矩形条高度比栈顶高度小，弹出栈顶矩形条，用新的栈顶矩形条和当前矩形条前一矩形条之间的间隔作为距离长度，计算最大面积，更新最大值
 * 重复这个判断直到再次遇到栈顶矩形条高度大于当前
 * 因为矩形条是按递增顺序存在栈里的，这个计算过程中生成的矩形中间的矩形条高度肯定比两边高度长，可以组成一个完整的矩形
 * 并且按这种方式向前扩张能依次计算每一个完整的矩形来更新最大值
 * 遍历完所有矩形条后，再放一个0高度的矩形条入栈，0会比前面所有矩形条的高度都小，会触发栈中剩余的矩形条按上面的方式进行最大面积计算
 */

// 19ms, beats 44.27%
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    for (int i = 0; i <= heights.size(); ++i) {
      int h = (i == heights.size() ? 0 : heights[i]);
      if (s.empty() || h >= heights[s.top()]) {
        s.push(i);
      } else {
        int tp = s.top();
        s.pop();
        max_area = max(max_area, heights[tp] * (s.empty() ? i : i - 1 - s.top()));
        --i;
      }
    }
    return max_area;
  }
};
