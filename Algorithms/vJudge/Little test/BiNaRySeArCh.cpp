/**
 * @problem: 二分
 * @link: https://vjudge.net/contest/570689#problem/E https://www.luogu.com.cn/problem/B3627
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  ll x; std::cin >> x;
  double lo = 1e-5, hi = 1e5;
	double eps = 1e-6;
	while (hi - lo > eps) {
		double mid = (lo + hi) / 2;
		if (mid * mid * mid >= x) hi = mid;
		else lo = mid;
	}
	/* 浮点数表示的整数有极小的误差, 可能会导致floor((double)100000) = 99999, 所以需要小小的调整一下. */
  std::cout << floor(lo + 0.000001) << '\n';
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
