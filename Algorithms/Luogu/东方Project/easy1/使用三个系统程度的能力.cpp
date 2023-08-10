/**
 * @problem: P7869 「Wdoi-4」使用三个系统程度的能力
 * @link: https://www.luogu.com.cn/problem/P7869
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

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
	std::string str; getline(std::cin, str);
	if (str.find("\\r\\n") != std::string::npos) std::cout << "windows\n";
	else if (str.find("\\n") != std::string::npos) std::cout << "linux\n";
	else std::cout << "mac\n";
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


