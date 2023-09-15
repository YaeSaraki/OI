/**
 * @problem: 5017. 垦田计划
 * @link: https://www.acwing.com/problem/content/5020/
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n, m, k; std::cin >> n >> m >> k;
  auto data = std::vector<PI>(n);
  for (int i = 0; i < n; ++i) std::cin >> data[i].first >> data[i].second;
  std::sort(ALL(data));

  auto check = [&](int avg) -> bool {
    i64 cnt = 0;
    for (int i = 0; i < n; ++i) {
      auto [a, b] = data[i];
      if (a > avg) cnt += (a - avg) * b;
    }
    if (cnt <= m) return true;
    else          return false;
  };

  int lo = data[0].first, hi = data[n - 1].first;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
  }

  std::cout << lo << "\n";
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