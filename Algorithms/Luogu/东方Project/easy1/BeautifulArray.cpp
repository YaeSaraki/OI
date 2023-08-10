/**
 * @problem: P7938 「Wdcfr-1」Beautiful Array
 * @link: https://www.luogu.com.cn/problem/P7938
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
	int n, m; std::cin >> n >> m;
	std::string str; std::cin >> str;
	int ans = 0, cnt = 0;
	for (int i = 0; i < n ; ++i) {
		if (str[i] == '(') ++cnt;
		else if (cnt) --cnt, ++ans;
	}
	std::cout << (ans >= m ? 1 : 0) << "\n";
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


