/**
 * \link: https://codeforces.com/contest/522/problem/A
 * \category: floyd  *special problem dfs and similar dp graphs trees *1200
 * 
 * 
 * 
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
using ll = long long;
using ull = unsigned ll;

const int kN = 233;
int n;
int num = 0;
int dp[kN][kN];

void Init() {
  for (int i = 0; i < kN; ++i) for (int j = 0; j < kN; ++j) {
    dp[i][j] = 0x3F3F3F3F;
  }
  return;
}

void Floyd() {
  for (int k = 1; k <= num; ++k) {
    for (int i = 1; i <= num; ++i) {
      for (int j = 1; j <= num; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  return ;
}

inline void solve() {
  Init();
  cin >> n;
  map<string, int> M;
  for (int i = 0; i < n; ++i) {
    string str1, drop, str2; cin >> str1 >> drop >> str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    if (!M.count(str1)) M.insert({str1, ++num});
    if (!M.count(str2)) M.insert({str2, ++num});
    dp[M[str1]][M[str2]] = 1;
  }
  Floyd();
  int ans = 0;
  for (int i = 1; i <= num; ++i) {
    for (int j = 1; j <= num; ++j) {
      if (dp[i][j] < 0x3F3F3F3F) ans = max(ans, dp[i][j]);
    }
  }
  return cout << ans + 1 << '\n', void();
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}