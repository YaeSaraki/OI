/**
 * @problem: 入门mex
 * @link: https://ac.nowcoder.com/acm/contest/62332/B
 * @category:
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

inline void solve() {
  size_t n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(ALL(a));
  a.erase(std::unique(ALL(a)), a.end());
  int i;
  for (i = 0; i < std::min(k, size(a)); ++i)
    if (a[i] != i) break;
  std::cout << i;
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
