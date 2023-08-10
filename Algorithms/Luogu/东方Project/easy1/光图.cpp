/**
 * @problem: P6159 [Cnoi2020] 光图
 * @link: https://www.luogu.com.cn/problem/P6159
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n, p, k; std::cin >> n >> p >> k;
	std::cout << p * k % n << "\n";
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


