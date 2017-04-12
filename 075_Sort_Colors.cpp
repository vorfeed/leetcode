#include "head.h"

/**
 https://leetcode.com/problems/sort-colors

 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 Note:
   You are not suppose to use the library's sort function for this problem.
 */

// refer to:
// modified

/**
 * 一个数组包含3种颜色，将相同颜色的放在一起
 */
/**
 * 类似快拍的partition，定义2个cursor，一个表示0当前排到的下一个位置，从头往后移
 * 另一个表示2当前排到的下一个位置，从尾往前移
 * 从头到尾开始遍历数据，遇到2时与two指针交换值，two指针前移，重复这个判断过程直到遇到非2值
 * 之后再判断是否为0，为0时与zero指针交换，zero指针后移，跟前面一样重复这个过程
 * 先和two指针进行判断是因为只有当当前处理到的下标大于zero指针时，前面对0的处理才能进行下去
 * 当遍历到和two指针相遇时，即zero指针前全为0，zero指针到当前位置全为1，当前位置（也即two指针位置）之后全为2，排序完成
 */

// 6ms, beats 1.79%
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int zero = 0, two = nums.size() - 1;
    for (int i = 0; i <= two; ++i) {
      while (nums[i] == 2 && i < two) {
        swap(nums[i], nums[two--]);
      }
      while (nums[i] == 0 && i > zero) {
        swap(nums[i], nums[zero++]);
      }
    }
  }
};
