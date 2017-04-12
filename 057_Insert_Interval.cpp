#include "head.h"

/**
 https://leetcode.com/problems/insert-interval

 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.

 Example 1:
   Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 Example 2:
   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

// refer to: https://discuss.leetcode.com/topic/28015/elegant-c-stl-solution-using-equal_range-to-find-overlapped-intervals
// modified

/**
 * 有序的不重叠区间中插入新的区间
 */
/**
 * 通过equal_range找出一对位置（第一个起点大于等于插入线段终点的线段，第一个起点大于插入线段终点的线段）
 * 如果找到的两个位置相同，说明插入线段的终点小于找到位置的线段的起点，并且插入线段和其他线段不重叠
 * 此时直接将线段插入找出的线段位置的前面
 * 如果两个位置不相同，前一个位置为遇到的第一个重叠的线段，后一个位置为重叠后遇到的第一个不重叠的线段，将所有重叠的线段做合并
 * 这里是都合并到最后一个重叠线段中，把其他重叠线段清除
 */

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// 19ms, beats 27.86%
class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    auto range = equal_range(intervals.begin(), intervals.end(), newInterval,
        [](const Interval &value, const Interval& element) {
      return value.end < element.start;
    });
    auto ite_start = range.first, ite_end = range.second;
    if (ite_start == ite_end) {
      intervals.insert(ite_start, newInterval);
    } else {
      ite_end--;
      ite_end->start = min(newInterval.start, ite_start->start);
      ite_end->end = max(newInterval.end, ite_end->end);
      intervals.erase(ite_start, ite_end);
    }
    return intervals;
  }
};
