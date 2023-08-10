/**
 * @problem: P1724 东风谷早苗
 * @link: https://www.luogu.com.cn/problem/P1724
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
	std::string str; std::cin >> str;
	int n = str.length();
	int t; std::cin >> t;
	int dx = 0, dy = 0;
	for (int i = 0 ; i < n; ++i) {
		char ch = str[i];
		switch (ch) {
			case 'N' : ++dy; break;
			case 'S' : --dy; break;
			case 'E' : ++dx; break;
			case 'W' : --dx; break;
			default: break;
		}
	}

	int rond = t / n;
	int x = rond * dx, y = rond * dy;
	int temp = t % n;

	for (int i = 0 ; i < temp; ++i) {
		char ch = str[i % n];
		switch (ch) {
			case 'N' : ++y; break;
			case 'S' : --y; break;
			case 'E' : ++x; break;
			case 'W' : --x; break;
			default: break;
		}
	}
	std::cout << x << " " << y << '\n';
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


