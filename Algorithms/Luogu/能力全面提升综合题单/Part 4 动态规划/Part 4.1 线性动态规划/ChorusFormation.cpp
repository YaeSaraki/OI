/**
 * @problem: P1091 [NOIP2004 提高组] 合唱队形
 * @link: https://www.luogu.com.cn/problem/P1091
 * @category: 动态规划 单调队列
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <array>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

const int kN = 101;
std::array<int, kN> peo, l, r;

inline void solve() {
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> peo[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (peo[i] > peo[j]) l[i] = std::max(l[i], l[j] + 1);
		}
	}

	for (int i = n; i; --i) {
		for (int j = n; j > i; --j) {
			if (peo[i] > peo[j]) r[i] = std::max(r[i], r[j] + 1);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt = std::max(cnt, l[i] + r[i]);
	if (cnt == 0) std::cout << "1\n";
	else std::cout << n - cnt - 1;
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


