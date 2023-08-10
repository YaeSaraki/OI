/**
 * @problem: P1095 [NOIP2007 普及组] 守望者的逃离
 * @link: https://www.luogu.com.cn/problem/P1095
 * @category: 动态规划 模拟
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

const int kN = 3e5  + 233;
std::array<int, kN> dp;

inline void solve() {
	int m, s, t; std::cin >> m >> s >> t;
	/* 闪现 */
	for (int i = 1; i <= t; ++i) {
		if (m >= 10) dp[i] = dp[i - 1] + 60, m -= 10;
		else dp[i] = dp[i - 1], m += 4;
	}

	/* 走路 */
	int the_farthest_way = 0;
	for (int i = 1; i <= t; ++i) {
		dp[i] = std::max(dp[i], dp[i - 1] + 17);
		if (dp[i] >= s) return std::cout << "Yes\n" << i << "\n", void();
	}
	return std::cout << "No\n" << dp[t] << "\n", void();
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


