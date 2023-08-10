/**
 * @problem: P1616 疯狂的采药
 * @link: https://www.luogu.com.cn/problem/P1616
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
	int t, k; std::cin >> t >> k;
	if (k == 1) {
		int w, v; std::cin >> w >> v;
		return std::cout << (t / w) * (ll)v, void();
	}
	std::vector<PI> herbs(k);
	int max = 0;
	for (int i = 0; i < k; ++i) std::cin >> herbs[i].first >> herbs[i].second;
	std::vector<int> dp(t + 1);
	for (int i = 0; i < k; ++i) {
		for (int j = herbs[i].first; j <= t; ++j) {
			dp[j] = std::max(dp[j], dp[j - herbs[i].first] + herbs[i].second);
		}
	}
	/*
	for (int i = 1; i <= t; ++i) {
		dp[i] = std::max(dp[i], dp[i - 1]);
		for (int j = 0; j < k; ++j) {
			if (i - herbs[j].first >= 0) dp[i] = std::max(dp[i], dp[i - herbs[j].first] + herbs[j].second);
		}
	}
	*/
	std::cout << dp[t] << "\n";
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


