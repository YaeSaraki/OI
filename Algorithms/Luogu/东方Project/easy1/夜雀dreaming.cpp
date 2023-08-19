/**
 * @problem: P7835 「Wdoi-3」夜雀 dreaming
 * @link: https://www.luogu.com.cn/problem/P7835
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <numeric>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
// #define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n, k; std::cin >> n >> k;
  std::vector<std::tuple<i64, i64, i64>> a(n);
  i64 ans = LONG_LONG_MAX;
  for (int i = 0;  i < k; ++i) {
    auto &[t1, x1, y1] = a[i];
    std::cin >> t1 >> x1 >> y1;
    for (int j = 0; j < i; ++j) {
      auto [t2, x2, y2] = a[j];
      
      i64 lcm = std::lcm(t1, t2);
      
      if ((x1 + (((lcm / t1) - 1) * y1)) % n !=
          (x2 + (((lcm / t2) - 1) * y2)) % n )
        ans = std::min(ans, lcm);
      
      lcm += lcm;
      if ((x1 + (((lcm / t1) - 1) * y1)) % n !=
          (x2 + (((lcm / t2) - 1) * y2)) % n )
        ans = std::min(ans, lcm);

    }
  }
  if (ans == LONG_LONG_MAX) std::cout << "Mystia will cook forever...";
  else                      std::cout << ans - 1;
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

