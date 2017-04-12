#include "head.h"

/**
 https://leetcode.com/problems/sliding-window-median

 Median is the middle value in an ordered integer list.
 If the size of the list is even, there is no middle value.
 So the median is the mean of the two middle value.

 Examples:
   [2,3,4] , the median is 3
   [2,3], the median is (2 + 3) / 2 = 2.5

 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 You can only see the k numbers in the window.
 Each time the sliding window moves right by one position.
 Your job is to output the median array for each window in the original array.

 For example,
   Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
   Window position                Median
   ---------------               -----
   [1  3  -1] -3  5  3  6  7       1
   1 [3  -1  -3] 5  3  6  7       -1
   1  3 [-1  -3  5] 3  6  7       -1
   1  3  -1 [-3  5  3] 6  7       3
   1  3  -1  -3 [5  3  6] 7       5
   1  3  -1  -3  5 [3  6  7]      6
   Therefore, return the median sliding window as [1,-1,-1,3,5,6].

 Note:
   You may assume k is always valid, ie: 1 ¡Ü k ¡Ü input array's size for non-empty array.
 */

// refer to: https://discuss.leetcode.com/topic/74963/o-n-log-k-c-using-multiset-and-updating-middle-iterator
// modified

/**
 * n个数的整数数组，滑动窗口大小为k，每次k往后移一格，计算每个窗口内的中位数（个数为奇数时取中间大小的数，偶数时取中间大小两个数的平均值）
 */
/**
 * 使用multiset作为滑动窗口，维护一个中间值得代码器（如果是奇数，迭代器指向中间值
 * 如果是偶数，迭代器指向取中间两个数中较大的数）
 * 将后面的数插入滑动窗口，判断新插入数的大小，如果小于中间值需要将mid迭代器往前移（奇数变偶数时，迭代器仍符合要求；偶数变奇数时，迭代器指向了后面大的数，需要迁移一格）
 * 删除最前面的数前也要判断是否小于等于中间值，是的话迭代器往后移（奇数变偶数时，迭代器指向了两个中间数较小的数，需要调整到较大的数上；偶数变奇数时，无需调整）
 * （如果删除的刚好为mid迭代器指向的值，迭代器会移动到后面大一点的数上，对后续操作无影响）
 */

// 69ms, beats 79.19%
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto ite_mid = next(window.begin(), k >> 1);
    vector<double> medians;
    for (size_t i = k; ; ++i) {
      medians.push_back(k & 1 ? *ite_mid :
          (static_cast<double>(*ite_mid) + *prev(ite_mid)) / 2);
      if (i == nums.size()) {
        break;
      }
      window.insert(nums[i]);
      if (nums[i] < *ite_mid) {
        --ite_mid;
      }
      if (nums[i - k] <= *ite_mid) {
        ++ite_mid;
      }
      window.erase(window.lower_bound(nums[i - k]));
    }
    return medians;
  }
};
