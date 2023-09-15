/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>

#define ONLINE_JUDGE


#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 1e5 + 233;

inline void solve() {
  int n, m; std::cin >> n >> m;
  auto a = std::vector<int>(kN);
  for (int i = 0; i < n; ++i) { int x, y; std::cin >> x >> y; a[x] += y;}
  int ans = 0, cnt = 0;
  for (int i = 0; i < m; ++i) cnt += a[i];
  for (int i = m; i < kN; ++i) {
    ans = std::max(ans , cnt);
    cnt += -a[i - m] + a[i];
  }
  std::cout << ans;
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
