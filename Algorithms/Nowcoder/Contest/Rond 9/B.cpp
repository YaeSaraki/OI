#include <algorithm>

#include <iostream>
#include <cstdint>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  auto a = std::vector<int>(n);
  for (auto &it : a) std::cin >> it;
  int idx = 0, maxx = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] * a[i + 1] > maxx) maxx = a[i] * a[i + 1], idx = i;
  }
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i == idx) { i += 1; continue; }
    sum += a[i];
  }
  sum += maxx;

  i64 sum2 = 0;
  for (int i = 0; i < n; ++i) sum2 += a[i];
  std::cout << std::max(sum, sum2);
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
