/**
 * @problem: 1272: ¿¨ÀòË¹Ëþ
 * @link: https://webvpn.shengda.edu.cn/webvpn/LjE1Ni4xNjYuMTcxLjIxNA==/LjE0OS4xNDkuMTY0LjE0OC4xNjguMjA2LjIwMi4xNjcuMTUxLjE0OS4xOTcuOTguMjAzLjE1My4xNzAuOTYuMTU2LjE2Mw==/problem.php?id=1272
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

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int a, b, x, c, m; std::cin >> a >> b >> x >> c >> m;

	int t = 0, mm = m;
	while (m > 0) {
		if (t && a + b * t >= m) {
			++t;
			break;
		}
		m -= x;
		++t;
	}

	int t2 = 0;
	int cd = 0, fs = 0;
	while (mm > 0) {
		if (cd <= 0 && fs) mm -= a + b, cd = c, fs = 0;
		else {
			if (cd <= 0) fs = 1;
			mm -= x, --cd;
		}
		++t2;
	}

	std::cout << std::min(t, t2) << "\n";
}

bool rt = true;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}


