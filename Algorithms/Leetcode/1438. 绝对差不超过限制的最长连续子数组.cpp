#include <algorithm>
#include <iostream>
#include <vector>
#include <set>


/** using sliding window & multiset. */
using namespace std;
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    int l = 0, r = 0, ans = 0;
    multiset<int> s;
    /** sliding window */
    while (r < n) {
      s.insert(nums.at(r));
      while (*s.rbegin() - *s.begin() > limit) s.erase(s.find(nums.at(l++)));
      ans = max(ans, r - l + 1);
      ++r;
    }
    
    return ans;
  }
};