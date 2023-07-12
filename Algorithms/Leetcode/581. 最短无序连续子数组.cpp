/**
 * \link: https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/
 * \category: 双指针 排序 array
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

/** using two pointers + math.　*/
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxx = INT_MIN, minn = INT_MAX; 
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (maxx <= nums.at(i)) maxx = nums.at(i);
      else r = i;
      if (minn >= nums.at(n - 1 - i)) minn = nums.at(n - 1 - i);
      else l = n - 1 - i;
    }
    return r == -1 ? 0 : r - l + 1;
  }
};

/** using sort. */
class Solution2 {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    if (is_sorted(nums.begin(), nums.end())) return 0;
    auto nums_sorted(nums);
    sort(nums_sorted.begin(), nums_sorted.end());
    int l = 0, r = n - 1;
    while (nums.at(l) == nums_sorted.at(l)) ++l;
    while (nums.at(r) == nums_sorted.at(r)) --r;
    return r - l + 1;
  }
};