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
#include <cmath>
#define ONLINE_JUDGE

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n, a, b; std::cin >> n >> a >> b;
  auto c = std::vector<int>(n);
  for (auto &it : c) std::cin >> it;

  auto check = [&](int mid) {
    int t = mid;
    for (int i = 0; i < n; ++i) {
      if (c[i] > mid * a) {
        int temp = c[i] - mid * a;
        t -= (int)std::ceil(temp * 1.0 / b);
        if (t < 0) return false;
      }
    }
    return true;
  };
  int lo = 1, hi = 5e5 + 233;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
  }
  std::cout << hi;
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
