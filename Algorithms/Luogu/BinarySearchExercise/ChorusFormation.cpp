/**
 * @problem: P1091 [NOIP2004 提高组] 合唱队形
 * @link: https://www.luogu.com.cn/problem/P1091
 * @category: 动态规划 单调队列
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

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n; std::cin >> n;
	std::vector<int> stu(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> stu[i];
	std::vector<std::vector<int> > f(n + 1, std::vector<int> (2));
	/* forward traversal. */
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (stu[j] < stu[i]) f[i][0] = std::max(f[i][0], f[j][0] + 1);
		}
	}

	/* backward traversal. */
	for (int i = n - 1; i; --i) {
		for (int j = n; j > i; --j) {
			if (stu[j] < stu[i]) f[i][1] = std::max(f[i][1], f[j][1] + 1);
		}
	}

	int cnt = INT_MIN;
	for (int i = 1; i <= n; ++i) cnt = std::max(cnt, f[i][0] + f[i][1]);
	int ans = 0;
	if (cnt == 0) ans = n;
	else ans = n - cnt - 1;

	// for (int i = 1; i <= n; ++i) std::cout << f[0][i];
	// std::cout << "\n";
	// for (int i = 1; i <= n; ++i) std::cout << f[1][i];
	// std::cout << "\n";

	std::cout << ans << '\n';
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


