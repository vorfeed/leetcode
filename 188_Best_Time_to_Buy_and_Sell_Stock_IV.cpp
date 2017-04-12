#include "head.h"

/**
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit.
 You may complete at most k transactions.

 Note:
   You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

// refer to: https://discuss.leetcode.com/topic/26169/clean-java-dp-solution-with-comment
// modified

/**
 * 给定每支股票在每天的价格，你只能买卖k次，必须卖掉后再买，计算最大收益
 */
/**
 * dp[i, j]：
 *     表示前j天的股票通过i次交易的最大收益
 * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
 *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))：
 *     分两种情况，取两者最大值：
 *         前面的每一天进行i-1次交易后的最大值，再买入那天的股票在第j天卖掉
 *         第j天不交易，和前一天一样
 * dp[i, 0]：
 *     第0天收益就是0
 * dp[0, j]：
 *     0次交易收益是0
 * i的取值范围是0-k，0表示没进行过交易
 * j的取值范围是0-prices.size()-1，0表示第一天
 */

// 9ms, beats 35.66%
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    // 说明每一次交易即使都在后面一天卖掉也有足够的次数，可以进行任意多次交易
    if (k >= prices.size() / 2) {
      int max_profit = 0;
      for (size_t i = 1; i < prices.size(); ++i) {
        max_profit += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
      }
      return max_profit;
    }
    vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
    for (int i = 1; i <= k; ++i) {
      int local_max = dp[i - 1][0] - prices[0];
      for (int j = 1; j < prices.size(); ++j) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + local_max);
        local_max = max(local_max, dp[i - 1][j] - prices[j]);
      }
    }
    return dp.back().back();
  }
};
