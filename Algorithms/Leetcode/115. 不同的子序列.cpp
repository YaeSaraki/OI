/**
 * \link: https://leetcode.cn/problems/distinct-subsequences/
 * \category: DP string 动态规划
 *
 *
 *
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;


/** using dp. */
class Solution {
 public:
  int numDistinct(string s, string t) {
    int ls = s.length(), lt = t.length();
    if (s.length() < t.length()) return 0;
    /** dp */
    vector<vector<ull> > dp(ls + 1, vector<ull>(lt + 1));
    /** find the bound */
    for (int i = 0; i <= ls; ++i) dp[i][lt] = 1;

    for (int i = ls - 1; ~i; --i) {
      for (int j = lt - 1; ~j; --j) {
        if (s.at(i) == t.at(j))
          dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
        else
          dp[i][j] = dp[i + 1][j];
      }
    }
    return dp[0][0];
  }
};

/** using dfs. */
class Solution {
 public:
  int ls, lt;
  vector<vector<ull> > mem;
  ull DFS(string s, int lss, string t, int ltt) {
    /** set the bound. */
    if (ltt == lt) return mem[lss][ltt] = 1;
    if (lss == ls) return mem[lss][ltt] = 0;

    if (mem[lss][ltt] != -1) return mem[lss][ltt];
    int cnt = 0;
    cnt += DFS(s, lss + 1, t, ltt);
    if (s.at(lss) == t.at(ltt)) cnt += DFS(s, lss + 1, t, ltt + 1);
    return mem[lss][ltt] = cnt; 
  }

  int numDistinct(string s, string t) {
    ls = s.length(), lt = t.length();
    mem = vector<vector<ull> >(ls, vector<ull> (lt, -1));
    return DFS(s, 0, t, 0); 
  }
};