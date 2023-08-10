/**
 * @problem: P1868 饥饿的奶牛
 * @link: https://www.luogu.com.cn/problem/P1868
 * @category: 动态规划 线性DP
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

const int kN = 2e5 + 233;
struct State {
	int left, right;
	int getSize() const { return right - left + 1; }
	bool operator<(const State & B) const {
		if (right != B.right) return right < B.right;
		return false;
	}
};

inline void solve() {
	int n; std::cin >> n;
	std::vector<State> b(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> b[i].left >> b[i].right;
	std::sort(b.begin() + 1, b.end());
	std::vector<int> dp(n + 2);
	for (int i = 1; i <= n; ++i) {
		auto it = std::lower_bound(b.begin() + 1, b.begin() + 1 + i - 1, (State){0, b[i].left});
	 	dp[i] = std::max(dp[i - 1], dp[it - (b.begin() + 1)] + b[i].getSize());
	}
	std::cout << dp[n] << "\n";
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


