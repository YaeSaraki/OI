/**
 * \link: https://leetcode.cn/problems/maximum-sum-circular-subarray/description/ 
 * \category: kadane math array dp 
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/** using kadane's algorithm. */
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    /** kadane's algorithm + circular updata. 
     * whether or not the maxSubArraySum isn't circal.
     * 1. yes) normal kadane algorithm-> maxSubArraySum.
     * 2. no) maxSubArraySumCircal = total - minSubArraySum.  */
    int max_sum = nums.at(0), min_sum = nums.at(0), 
        cur_max_sum = 0, cur_min_sum = 0, total = 0;
    for (auto it : nums) {
      cur_max_sum = it + max(cur_max_sum, 0);
      max_sum = max(max_sum, cur_max_sum);
      cur_min_sum = it + min(cur_min_sum, 0);
      min_sum = min(min_sum, cur_min_sum);
      total += it;
    }

    /** if all the nums are minus, the max should equal the max num instead of
     * 0(total - min_sum(total)). */
    return (max_sum > 0 ? max(max_sum, total - min_sum) : max_sum);
  
  }
};