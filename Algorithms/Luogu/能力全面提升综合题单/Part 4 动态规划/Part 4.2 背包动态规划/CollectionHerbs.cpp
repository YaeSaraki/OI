/**
 * @problem: P1048 [NOIP2005 普及组] 采药
 * @link: https://www.luogu.com.cn/problem/P1048
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

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int t, m; std::cin >> t >> m;
	std::vector<std::pair<int, int> > herbs(m + 1);
	for (auto &it : herbs) std::cin >> it.first >> it.second;
	herbs.insert(herbs.begin(), {0, 0});
	std::vector<std::vector<int> > dp(m + 1, std::vector<int> (t + 1));
	for (int i = 1; i <= m; ++i) {
		for (int j = t; j; --j) {
			if (j - herbs[i].first >= 0) dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - herbs[i].first] + herbs[i].second);
			else dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
		}
	}

#ifndef DBG
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= t; ++j) {
			std::cout << dp[i][j] << " ";
		}
		std::cout << "\n";
	}
#endif

	int ans = 0;
	ans = *max_element(ALL(dp[m]));
	std::cout << ans << "\n";
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


