/**
 * @problem: P8466 [Aya Round 1 A] 幻想乡扑克游戏
 * @link: https://www.luogu.com.cn/problem/P8466
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
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	std::string str; std::cin >> str;
	auto m = std::map<char, int>();
	for (int i = 0; i < str.length(); ++i) ++m[str[i]];
	bool flag = false;
	if (m.count('D') && m.count('X')) flag = true;
	for (auto it : m) if (it.second >= 4) { flag = true; break; }
	std::cout << (flag ? "YES\n" : "NO\n");
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


