#include "head.h"

/**
 https://leetcode.com/problems/median-of-two-sorted-arrays

 There are two sorted arrays nums1 and nums2 of size m and n respectively.
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Example 1:
   nums1 = [1, 3]
   nums2 = [2]
   The median is 2.0

 Example 2:
   nums1 = [1, 2]
   nums2 = [3, 4]
   The median is (2 + 3)/2 = 2.5
 */

// refer to: https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
// modified

/**
 * 两个有序数组的中位数
 */
/**
 * 考虑将两个数组分别分成两段（m<n）
 *       left_part          |        right_part
 * A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
 * B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
 * 当满足条件：
 *   1）分割线左右两边个数相同
 *   2）分割线左边最大值小于等于右边最小值
 * 时，认为分割线左边最大值小于和右边最小值的均值记为所求中位数
 * 上面两个条件可以继续演绎为：
 *   1）i + j == m - i + n - j (or: m - i + n - j + 1)
 *   2）B[j-1] <= A[i] and A[i-1] <= B[j]
 * 基于这个思路就可以进行查找了
 * 首先将短的那个数组均分成两段，二分查找确定i的值，那么另一个j的值就被定为两个数组总长度-i，分三种情况：
 *   1）B[j-1] > A[i]，i靠后了，需要前移
 *   2）A[i-1] > B[j]，i靠前了，需要后移
 *   3）确定中位数，分多种情况：可能分别在两个数组中，也可能在一个数组中，还需考虑总数奇偶的情况
 * 时间O(log(min(m+n)))，空间O(1)
 */

// 32ms, beats 84.70%
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    if (nums1.empty()) {
      return nums2.size() & 1 ? nums2[nums2.size() >> 1] :
          (nums2[nums2.size() >> 1 - 1] + nums2[nums2.size() >> 1]) >> 1;
    }
    int imin = 0, imax = nums1.size(), half_len = (nums1.size() + nums2.size() + 1) >> 1;
    while (imin <= imax) {
      int i = (imin + imax) >> 1;
      int j = half_len - i;
      if (i < nums1.size() && nums2[j - 1] > nums1[i]) {
        imin = i + 1;
      } else if (i > 0 && nums1[i - 1] > nums2[j]) {
        imax = i - 1;
      } else {
        int max_of_left = 0, min_of_right = 0;
        if (!i) {
          max_of_left = nums2[j - 1];
        } else if (!j) {
          max_of_left = nums1[i - 1];
        } else {
          max_of_left = max(nums1[i - 1], nums2[j - 1]);
        }
        // 奇数直接返回中间值
        if ((nums1.size() + nums2.size()) & 1 == 1) {
          return max_of_left;
        }
        if (i == nums1.size()) {
          min_of_right = nums2[j];
        } else if (j == nums2.size()) {
          min_of_right = nums1[i];
        } else {
          min_of_right = min(nums1[i], nums2[j]);
        }
        return (max_of_left + min_of_right) / 2.0;
      }
    }
    return 0.;
  }
};
