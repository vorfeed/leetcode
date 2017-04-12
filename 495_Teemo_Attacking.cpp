#include "head.h"

/**
 https://leetcode.com/problems/teemo-attacking

 In LLP world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned condition.
 Now, given the Teemo's attacking ascending time series towards Ashe and the poisoning time duration per Teemo's attacking, you need to output the total time that Ashe is in poisoned condition.
 You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be in poisoned condition immediately.

 Example 1:
   Input: [1,4], 2
   Output: 4
   Explanation:
     At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately.
     This poisoned status will last 2 seconds until the end of time point 2.
     And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds.
     So you finally need to output 4.

 Example 2:
   Input: [1,2], 2
   Output: 3
   Explanation:
     At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned.
     This poisoned status will last 2 seconds until the end of time point 2.
     However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status.
     Since the poisoned status won't add up together, though the second poisoning attack will still work at time point 2, it will stop at the end of time point 3.
     So you finally need to output 3.

 Note:
   You may assume the length of given time series array won't exceed 10000.
   You may assume the numbers in the Teemo's attacking time series and his poisoning time duration per attacking are non-negative integers, which won't exceed 10,000,000.
 */

// refer to:
// modified

/**
 * 输入一组时间点和一个固定的中毒持续时间，在每个时间点上开始都会持续固定时间的中毒（中毒时间之间可能有重叠），求总的中毒时间
 */
/**
 * 遍历每个时间点，根据上一次记录的中毒起始时间判断本次中毒能延续的时间，同时更新中毒起始时间
 */

// 66ms, beats 52.15%
class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) {
      return 0;
    }
    int begin = timeSeries.front(), total = duration;
    for (int i = 1; i < timeSeries.size(); ++i) {
      total += timeSeries[i] < begin + duration ? timeSeries[i] - begin : duration;
      begin = timeSeries[i];
    }
    return total;
  }
};
