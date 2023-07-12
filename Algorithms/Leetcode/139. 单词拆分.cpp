/**
 * \link: https://leetcode.cn/problems/word-break/ 
 * \category: dp 动态规划 hash array string
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> workDictSet(wordDict.begin(), wordDict.end()); 
    int n = s.length();
    vector<bool> dp(n + 1);
    /** init */
    dp[0] = true;
    /** dp */
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && workDictSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};