#include "head.h"

/**
 https://leetcode.com/problems/edit-distance

 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:
   a) Insert a character
   b) Delete a character
   c) Replace a character
 */

// refer to:
// modified

/**
 * 编辑距离
 */
/**
 * 创建dp数据
 * dp[i][j]表示从word1[0..i - 1]转换成word2[0..j - 1]最少需要多少步操作
 * 如果word1[i - 1]与word2[j - 1]相同，无需新操作，dp[i][j] = dp[i - 1][j - 1]
 * 如果不相同，分3种情况：
 *   1）替换，即将word1[i - 1]字符用word2[j - 1]字符替换，等同于dp[i - 1][j - 1]的操作次数加一次替换操作，dp[i][j] = dp[i - 1][j - 1] + 1
 *   2）删除，即删除word1[i - 1]这个字符，等同于将word1[0..i - 2]转换为word2[0..j - 1]需要的操作次数加一次删除操作，dp[i][j] = dp[i - 1][j] + 1
 *   3）插入，即word1[0..i - 1]后面插入一个word2[j - 1]字符后变成word2[0..j - 1]，等同于上述新word1到word2的转换操作次数加一次插入操作，dp[i][j] = dp[i][j - 1] + 1
 * 边界条件：
 *   1）任何字符串转成空串都需要字符串长度次操作，dp[i][0] = i
 *   2）空串转任何字符串都需要转换后的字符串长度次操作，dp[0][j] = j
 */

// 16ms, beats 51.53%
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= n; ++j) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1] + 1,
              min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
        }
      }
    }
    return dp[m][n];
  }
};
