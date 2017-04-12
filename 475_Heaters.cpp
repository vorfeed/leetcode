#include "head.h"

/**
 https://leetcode.com/problems/heaters

 Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
 Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
 So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

 Note:
   Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
   Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
   As long as a house is in the heaters' warm radius range, it can be warmed.
   All the heaters follow your radius standard and the warm radius will the same.

 Example 1:
   Input: [1,2,3],[2]
   Output: 1
   Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

 Example 2:
   Input: [1,2,3,4],[1,4]
   Output: 1
   Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
 */

// refer to: https://discuss.leetcode.com/topic/71440/c-solution-using-lower_bound-binary-search-with-comments
// modified

/**
 * 给定一组房子的位置和一组暖气的位置（一维），求暖气的最小辐射半径（所有暖气辐射半径相同），使所有房子都能被暖气覆盖到
 */
/**
 * 对暖气的位置排序，遍历每个房子，找出离房子左右两边最近的暖气的距离，对所有房子的这个最小距离取最大值
 */

// 96ms, beats 48.62%
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int min_radius = 0;
    for (size_t i = 0; i < houses.size(); ++i) {
      int cur_radius = numeric_limits<int>::max();
      auto ite_larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
      if (ite_larger != heaters.end()) {
        cur_radius = *ite_larger - houses[i];
      }
      if (ite_larger != heaters.begin()) {
        cur_radius = min(cur_radius, houses[i] - *--ite_larger);
      }
      min_radius = max(min_radius, cur_radius);
    }
    return min_radius;
  }
};
