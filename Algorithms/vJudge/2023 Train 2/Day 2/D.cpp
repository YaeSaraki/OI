#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <numeric>
#include <functional>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

#define ONLINE_JUDGE

using i64 = int64_t;
using PI = std::pair<int, int>;


inline void solve() {
  int n, m, k, w; std::cin >> n >> m >> k >> w;
  auto resource = std::vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> resource[i];
  auto team = std::vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> team[i];

  auto f = std::vector<int>(n + 1);
  
  std::iota(ALL(f), 0);
  
  std::function<int(int)> Find = [&](int x) { return x == f[x] ? x : f[x] = Find(f[x]); };

  std::function<void(int, int)> Union = [&](int x, int y) { int a = Find(x), b = Find(y); f[a] = b; };

  while (m--) {
    int x, y; std::cin >> x >> y;
    if (team[x] == 1 && team[y] == 1) Union(x, y);
  }

  auto _a = std::vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (team[i] == 1) _a[Find(i)] += resource[Find(i)];
  }
  std::sort(a[i]);
  int ans = 0;
  for (int i = n - k; i <= n; ++i) ans += _a[i];
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
