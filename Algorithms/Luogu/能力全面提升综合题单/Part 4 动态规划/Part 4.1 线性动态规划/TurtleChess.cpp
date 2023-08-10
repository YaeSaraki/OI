/**
 * @problem: P1541 [NOIP2010 提高组] 乌龟棋
 * @link: https://www.luogu.com.cn/problem/P1541
 * @category: 动态规划 dp 递归 枚举
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

const int kN = 41;
int dp[kN][kN][kN][kN];

inline void solve() {
	int n, m; std::cin >> n >> m;
	std::vector<int> chessboard(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> chessboard[i];

	std::vector<int> card(5);
	for (int i = 1; i <= m; ++i) { int x; std::cin >> x; ++card[x]; }

	dp[0][0][0][0] = chessboard[1];
	for (int i = 0; i <= card[1]; ++i) for (int j = 0; j <= card[2]; ++j)
		for (int k = 0; k <= card[3]; ++k) for (int l = 0; l <= card[4]; ++l) {
			int maxx = 0;

			if (i) maxx = std::max(maxx, dp[i - 1][j][k][l]);
			if (j) maxx = std::max(maxx, dp[i][j - 1][k][l]);
			if (k) maxx = std::max(maxx, dp[i][j][k - 1][l]);
			if (l) maxx = std::max(maxx, dp[i][j][k][l - 1]);

			/* <!> 初始坐标为1，故step 要加上1 */
			int step = 1 + i * 1 + j * 2 + k * 3 + l * 4;
			dp[i][j][k][l] = maxx + chessboard[step];
	}
	std::cout << dp[card[1]][card[2]][card[3]][card[4]] << "\n";
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


