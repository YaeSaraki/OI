/**
 * \link: https://leetcode.cn/problems/trapping-rain-water/description/
 * \category: 双指针 stak array two pointers 
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

/** using 动态规划
 * For indix i, the maximum height that water can reach afer rain is equal to
 * the lower profile of the maximum height on both sides of indix i. And the
 * amount of the rain can be receiced at indix i is equal to the maximum height
 * at indix i minus the height at indix i. */
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    /** left max */
    vector<int> left_max(height);
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
      maxx = max(maxx, height[i]);
      left_max[i] = maxx;
    }

    /** right max */
    vector<int> right_max(height);
    maxx = 0;
    for (int i = n - 1; ~i; --i) {
      maxx = max(maxx, height[i]);
      right_max[i] = maxx;
    }

    /** both sides */
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += min(left_max[i], right_max[i]) - height[i];
    }

    return ans;
  }
};

/** using monotonic stack. */
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && height.at(i) > height.at(stk.top())) {
        int top = stk.top();
        stk.pop();
        if (stk.empty()) break;
        int l = stk.top();
        int width_now = i - 1 - l;
        int height_now = min(height.at(i), height.at(l)) - height.at(top);
        ans += height_now * width_now;
      }
      stk.push(i);
    }
    return ans;
  }
};
