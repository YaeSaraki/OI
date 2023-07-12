/**
 * \link:
 *https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * \category: hash string sliding window
 *
 *
 *
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) { 
    if (s.length() == 0) return 0;
    unordered_set<char> loopup;
    int ans = 0, rk = 0, n = s.length();
    for (int i = 0; i < n; ++i) {
      if (i != 0) loopup.erase(s[i - 1]);
      while (rk < n && !loopup.count(s[rk])) {
        loopup.insert(s[rk++]);
      }
      ans = max(ans, rk - i);
    }
    return ans;
  }
};
