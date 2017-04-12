#include "head.h"

/**
 https://leetcode.com/problems/ipo

 Suppose LeetCode will start its IPO soon.
 In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO.
 Since it has limited resources, it can only finish at most k distinct projects before the IPO.
 Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

 You are given several projects.
 For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project.
 Initially, you have W capital.
 When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

 To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.

 Example 1:
   Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
   Output: 4
   Explanation:
     Since your initial capital is 0, you can only start the project indexed 0.
     After finishing it you will obtain profit 1 and your capital becomes 1.
     With capital 1, you can either start the project indexed 1 or the project indexed 2.
     Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
     Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

 Note:
   You may assume all numbers in the input are non-negative integers.
   The length of Profits array and Capital array will not exceed 50,000.
   The answer is guaranteed to fit in a 32-bit signed integer.
 */

// refer to: https://discuss.leetcode.com/topic/78574/8-liner-c-42ms-beat-98-greedy-algorithm-detailed-explanation
// modified

/**
 * 给定一组项目的耗费C和完成后的收益P（已扣除成本的纯利润），你只能选择k个项目，以启动资本W开始，求最大收益
 */
/**
 * 将项目分成两类：可启动的和暂时无法启动的
 * 使用贪心算法，每次从可启动项目中取出收益最多的，加入到当前总收益中，重新判断暂时无法启动项目中哪些变成可启动了，更新到可启动项目中
 * 重复这个过程，选k个项目
 */

// 59ms, beats 46.9%
class Solution {
public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits,
      vector<int>& Capital) {
    priority_queue<int> low;
    multiset<pair<int, int>> high;
    for (int i = 0; i < Profits.size(); ++i) {
      if (Profits[i] > 0) {
        if (Capital[i] <= W) {
          low.push(Profits[i]);
        } else {
          high.emplace(Capital[i], Profits[i]);
        }
      }
    }
    while (k-- && low.size()) {
      W += low.top();
      low.pop();
      auto ite = high.upper_bound(make_pair(W, numeric_limits<int>::max()));
      if (ite != high.begin()) {
        for (auto ite_lower = high.begin(); ite_lower != ite; ++ite_lower) {
          low.push(ite_lower->second);
        }
        high.erase(high.begin(), ite);
      }
    }
    return W;
  }
};
