#include "head.h"

/**
 https://leetcode.com/problems/merge-intervals

 Given a collection of intervals, merge all overlapping intervals.

 For example,
   Given [1,3],[2,6],[8,10],[15,18],
   return [1,6],[8,10],[15,18].
 */

// refer to:
// modified

/**
 * 区间合并
 */
/**
 * 按起始位置排序后判断重叠，合并
 */

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// 59ms, beats 7.16%
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return {};
    }
    vector<Interval> ret;
    sort(intervals.begin(), intervals.end(),
        [](const Interval& lhs, const Interval& rhs) {
      return lhs.start < rhs.start;
    });
    ret.push_back(intervals.front());
    for (const Interval& interval : intervals) {
      if (ret.back().end < interval.start) {
        ret.push_back(interval);
      } else {
        ret.back().end = max(ret.back().end, interval.end);
      }
    }
    return ret;
  }
};
