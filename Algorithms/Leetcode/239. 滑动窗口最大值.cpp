/**
 * \link: https://leetcode.cn/problems/sliding-window-maximum/
 * \category: sliding window monotonic queue 
 * 
 * 
 * 
 **/
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/** using priority queue O(n*logn) */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int> > q;
    /** emplace the first k nums to the priority queue and put the first ans */
    for (int i = 0; i < k; ++i)
      q.emplace(nums.at(i), i);  // new .emplace() in priority_queue => .insert()
    vector<int> ans = {q.top().first};

    /** sliding widow */
    for (int i = k; i < n; ++i) {
      q.emplace(nums.at(i), i);
      while (q.top().second <= i - k) q.pop();
      ans.push_back(q.top().first); 
    }

    return ans;
  }
};

/** using monotonic queue O(n) */
class Solution2 {
  public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    ans.reserve(n);
    deque<int> q;
    /** sliding window */
    for (int i = 0; i < n; ++i) {
      /** if the noob is better than you, you should retire. */
      while (!q.empty() && nums.at(i) >= nums.at(q.back())) q.pop_back();
      
      q.push_back(i);
      /** remove those nums that have already slid out and start puting ans at pos:k - 1 */
      if (i >= k - 1) {
        while (q.front() <= i - k) q.pop_front();
        ans.push_back(nums.at(q.front()));
      }

    }
    return ans;
  }
};