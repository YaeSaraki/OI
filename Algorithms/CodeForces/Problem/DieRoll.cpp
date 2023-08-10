/**
 * @problem: Die Roll
 * @link: https://www.luogu.com.cn/problem/CF9A
 * @category: math 递归 gcd
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <numeric>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int y, w; std::cin >> y >> w;
  int maxx = 6 -  (std::max(y, w) - 1);
  std::cout << maxx / std::gcd(6, maxx) << '/' << 6 / std::gcd(6, maxx) << '\n';
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
