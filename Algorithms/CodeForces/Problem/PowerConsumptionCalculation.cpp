/**
 * @problem: Ancient Berland Circus
 * @link: https://codeforces.com/problemset/problem/1/C
 * @category: geometry math *2100
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

struct Interval {
  int start, end;
  [[nodiscard]] int period() const { return end - start; }
} itv[105];

inline void solve() {
  int n; std::cin >> n;
  int p1, p2, p3; std::cin >> p1 >> p2 >> p3;
  int t1, t2; std::cin >> t1 >> t2;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> itv[i].start >> itv[i].end;
    ans += itv[i].period() * p1;
  }
  for (int i = 0; i < n - 1; ++i) {
    int t = itv[i + 1].start - itv[i].end;
    if (t <= t1) ans += t * p1;
    else if (t > t1 && t <= t1 + t2) ans += t1 * p1 + (t - t1) * p2;
    else ans += t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
  }
  std::cout << ans << ' ';
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

