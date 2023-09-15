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
  int m, x; std::cin >> m >> x;
  int ans = x % m;
  if (ans == 0) std::cout << m << "\n";
  else std::cout << ans << "\n";
}

bool rt = true;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}