/**
 * @problem: P8225 「Wdoi-5」天才⑨与天才拆分
 * @link: https://www.luogu.com.cn/problem/P8225
 * @category: 思维
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
	i64 k, n; std::cin >> k >> n;
	i64 nine = 0;
	for (int i = 0; i < k; ++i) nine = (nine << 1) + (nine << 3) + 9;
	std::cout << (n % nine ? "baka\n" : "aya\n");
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


