/**
 * @problem: P8534 「Wdoi-2」比赤色更红的梦
 * @link: https://www.luogu.com.cn/problem/P8534
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

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	i64 stage, score; std::cin >> stage >> score;
	std::cout << 2 + (stage >= 3) + (stage >= 5) + (score >= 10000000) + (score >= 20000000) +
																								 (score >= 40000000) + (score >= 60000000) << "\n";
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


