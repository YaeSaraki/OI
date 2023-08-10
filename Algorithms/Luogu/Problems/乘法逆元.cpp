/**
 * @problem: P3811 【模板】乘法逆元
 * @link: https://www.luogu.com.cn/problem/P3811
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
	int n, p; std::cin >> n >> p;
	std::vector<i64> div(n + 1);
	std::cout << (div[1] = 1LL) << "\n";
	for (int i = 2; i <= n; ++i) {
		div[i] = (i64)(p - p / i) * div[p % i] % p;
		std::cout << div[i] << "\n";
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


