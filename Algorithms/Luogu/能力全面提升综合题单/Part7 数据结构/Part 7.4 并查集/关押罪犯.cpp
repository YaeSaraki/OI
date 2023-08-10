/**
 * @problem: P1525 [NOIP2010 提高组] 关押罪犯
 * @link: https://www.luogu.com.cn/problem/P1525
 * @category: 并查集 二分图
 * @date:
 * @Author: YaeSaraki
 **/
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

struct Data {
	int a, b, level;
	bool operator<(const Data &B) const {
		if (level != B.level) return level < B.level;
		return false;
	}
};

inline void solve() {
	int n, q; std::cin >> n >> q;
	std::priority_queue<Data> data;

	for (int i = 0; i < q; ++i) {
		Data temp; std::cin >> temp.a >> temp.b >> temp.level;
		data.emplace(temp);
	}

	/* f[]
	 * 1 - n      : 自己
	 * n + 1 - 2n : 敌人
	 */
	auto f = std::vector<int>(n * 2 + 1);
	std::iota(ALL(f), 0);

	std::function<int(int)> Find = [&](int x) -> int {
		return x == f[x] ? x : f[x] = Find(f[x]);
	};
	std::function<void(int, int)> Union = [&](int a, int b) {
		int x = Find(a), y = Find(b);
		f[x] = y;
	};

	while (!data.empty()) {
		auto [a, b, level] = data.top(); data.pop();
		if (Find(a) == Find(b)) return std::cout << level << "\n", void();
		Union(a + n, b);
		Union(b + n, a);
	}
	std::cout << "0\n";
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


