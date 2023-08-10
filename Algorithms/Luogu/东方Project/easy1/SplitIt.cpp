/**
 * @problem: Split it!
 * @link: https://www.luogu.com.cn/problem/CF1496A
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/




#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n, k; std::cin >> n >> k;
	std::string str; std::cin >> str;
	int cnt = 0;
	for (int i = 0, j = n - 1; i < j; ++i, --j, ++cnt) if (str[i] != str[j]) break;
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


