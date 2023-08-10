/**
 * @problem: https://www.luogu.com.cn/problem/P1216
 * @link: P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles
 * @category: 线性dp
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
	int n; std::cin >> n;
	std::vector<std::vector<int> > dp(n + 1, std::vector<int> (n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cin >> dp[i][j];
			dp[i][j] += std::max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = std::max(ans, dp[n][i]);
	std::cout << ans;
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


