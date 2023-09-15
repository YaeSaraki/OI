/**
 * @problem: P1010 [NOIP1998 普及组] 幂次方
 * @link: https://www.luogu.com.cn/problem/P1010
 * @category: 分治
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

std::string f(int n) {
  if (n == 0) return std::string("0");
  std::string s("");
  int i = 0;
  do {
    if (n & 1) s = (i == 1 ? "2" : "2(" + f(i) + ")") + (s == "" ? "" : "+") + s;
  } while (++i, n >>= 1);
  return s;
}

inline void solve() {
  int n; std::cin >> n;
  std::cout << f(n) << '\n';
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
