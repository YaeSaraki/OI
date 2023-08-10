/**
 * @problem: P5514 [MtOI2019] 永夜的报应
 * @link: https://www.luogu.com.cn/problem/P5514
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


/** a ^ b < a + b */
inline void solve() {
	int n; std::cin >> n;
	/* ans 初始为0不会影响异或结果 */
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; std::cin >> x;
		ans ^= x;
	}
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


