/**
 * @problem: P8468 [Aya Round 1 C] 文文的构造游戏
 * @link: https://www.luogu.com.cn/problem/P8468
 * @category: XOR
 * @date: 
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int s, m; std::cin >> s >> m;
  if (s & 1) std::cout << -1 << "\n";
  else std::cout << 2 << " " << s / 2 << " " << s / 2 << "\n";
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
