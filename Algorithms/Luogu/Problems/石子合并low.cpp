/**
 * @problem: P1775 石子合并（弱化版）
 * @link: https://www.luogu.com.cn/problem/P1775
 * @category: 区间DP
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <numeric>


#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n; std::cin >> n;
	std::vector<int> a(n), sum(n + 1);
	for (auto &it : a) std::cin >> it;
	a.insert(a.begin(), 0);
	std::partial_sum(ALL(a), sum.begin());
	std::vector<std::vector<int> > dp(n + 1, std::vector<int> (n + 1));
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int left = i, right = i + len - 1;
			dp[left][right] = INT_MAX;
			for (int k = left; k < right; ++k) {
				dp[left][right] = std::min(dp[left][right], dp[left][k] + dp[k + 1][right] + sum[right] - sum[left - 1]);
			}
		}
	}
	std::cout << dp[1][n];
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


