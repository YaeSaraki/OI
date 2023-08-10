/**
 * @problem: 完全平方数
 * @link: https://ac.nowcoder.com/acm/contest/62332/E
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <cmath>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; std::cin >> x;
    int sq = (int)sqrt(x);
    if (sq * sq == x) ++ans;
  }
  std::cout << ans << '\n';
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
