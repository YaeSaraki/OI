/**
 * @problem: P7505 「Wdsr-2.5」小小的埴轮兵团
 * @link: https://www.luogu.com.cn/problem/P7505
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n, m, k; std::cin >> n >> m >> k;
	auto a = std::vector<int>(n);
	for (auto &it : a) std::cin >> it;
	std::sort(ALL(a));
	auto que = std::deque<int>(ALL(a));
	i64 move = 0;
	while (m--) {
		int op; std::cin >> op;
		if        (op == 1) {
			int x; std::cin >> x;
			move += x;
			while (!que.empty() && que.back() + move > k) que.pop_back();
		} else if (op == 2) {
			int x; std::cin >> x;
			move -= x;
			while (!que.empty() && que.front() + move < -k) que.pop_front();
		} else if (op == 3) {
			std::cout << que.size() << "\n";
		}
	}
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


