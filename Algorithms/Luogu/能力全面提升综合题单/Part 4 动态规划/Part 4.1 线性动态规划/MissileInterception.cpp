/**
 * @problem: P1020 [NOIP1999 普及组] 导弹拦截
 * @link: https://www.luogu.com.cn/problem/P1020
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

const int kN = 5e4 + 233;
std::vector<int> dp1(kN, 0x3F3F3F3F), dp2(kN);

inline void solve() {
	int cnt1 = 0, cnt2 = 0;
	int x; while (std::cin >> x) {
		if (x <= dp1[cnt1]) dp1[++cnt1] = x;
		else *std::upper_bound(dp1.begin() + 1, dp1.begin() + cnt1, x, std::greater<int>()) = x;

		if (x > dp2[cnt2]) dp2[++cnt2] = x;
		else *std::lower_bound(dp2.begin() + 1, dp2.begin() + cnt2, x) = x;
	}
	std:: cout << cnt1 << "\n" << cnt2 << "\n";
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


