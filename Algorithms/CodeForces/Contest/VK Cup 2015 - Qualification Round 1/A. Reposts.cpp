/**
 * @problem:
 * @link: https://codeforces.com/contest/522/problem/A
 * @category: floyd *special problem dfs and similar dp graphs trees *1200
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <map>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

const int kN = 233;

inline void solve() {
  int n; std::cin >> n;
  int cnt = 0;
  std::map<std::string, int> m;
  std::vector<std::vector<int> > dp(kN, std::vector<int> (kN, 0x3F3F3F3F));
  for (int i = 0; i < n; ++i ) {
    std::string name1, drop, name2; std::cin >> name1 >> drop >> name2;
    std::transform(ALL(name1), name1.begin(), ::tolower);
    std::transform(ALL(name2), name2.begin(), ::tolower);
    if (!m.count(name1)) m.emplace(name1, cnt++);
    if (!m.count(name2)) m.emplace(name2, cnt++);
    dp[m[name1]][m[name2]] = 1;
  }
  /* floyd */
  for(int k = 0; k < cnt; ++k) {
    for (int i = 0; i < cnt; ++i) {
      for (int j = 0; j < cnt; ++j) {
          dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < cnt; ++j) {
      if (dp[i][j] < 0x3F3F3F3F) ans = std::max(ans, dp[i][j]);
    }
  }

  std::cout << ans + 1 << '\n';
}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
