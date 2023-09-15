#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

#define ONLINE_JUDGE

using i64 = int64_t;
using PI = std::pair<int, int>;


inline void solve() {
  int n, m; std::cin >> n >> m;
  auto a = std::vector<i64>(n);
  for (auto &it : a) std::cin >> it;

  while (m--) {
    int left, right, x; std::cin >> left >> right >> x;
    --left, --right;
    i64 ans = 0;
    for (int i = left; i <= right; ++i) ans |= a[i];
    ans |= x;
    std::cout << ans << "\n";
  }
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
