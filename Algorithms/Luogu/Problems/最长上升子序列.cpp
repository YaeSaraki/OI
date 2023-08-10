/**
 * @problem: T206418 【模板】最长上升子序列
 * @link: https://www.luogu.com.cn/problem/T206418
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n; std::cin >> n;
	std::vector<int> a(n), dp(n + 1);
	for (auto &it : a) std::cin >> it;
	dp[0] = INT_MIN;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > dp[cnt]) dp[++cnt] = a[i];
		else *std::lower_bound(dp.begin() + 1, dp.begin() + 1 + cnt, a[i]) = a[i];
	}
	std::cout << cnt;
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


