/**
 * \link: https://leetcode.cn/problems/longest-nice-subarray/solutions/ 
 * \category: sliding window bit operation array
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/** using sliding window + bit operation. */
class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    auto n = nums.size();
    int ans = 0;
    if (n == 1) return ans = 1;
    /** sliding window. */
    int l = 0, r = 0, now = 0;
    while (r < n) {
      /** if the and of the result is not 0, then the left of the slidng window
       * needs to be move next. For each number leave the window, we can use the
       * now result to do a xor operation with it. */
      while (l < r && ((now & nums.at(r)) != 0)) now ^= nums.at(l++);
      now |= nums.at(r); // new |or operation to add a num, ^xor operation to delete a num.

      ans = max(ans, r - l + 1);
      ++r;
    }

    return ans;
  }
};