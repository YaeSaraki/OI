/**
 * @problem: P6832 [Cnoi2020] 子弦
 * @link: https://www.luogu.com.cn/problem/P6832
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
	std::string str; std::cin >> str;
	std::map<char, int> m;
	for (auto it : str) ++m[it];
	int ans = 0;
	for (auto it : m) ans = std::max(ans, it.second);
	std::cout << ans << "\n";
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
