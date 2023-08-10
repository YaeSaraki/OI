/**
 * @problem: 序列的与和
 * @link: https://ac.nowcoder.com/acm/contest/62880/B
 * @category: 位运算
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

/* 状态压缩 2 */
inline void solve2() {
	int n, k; std::cin >> n >> k;
	std::vector<signed long long> a(n);
	for (auto &it : a) std::cin >> it;
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		std::bitset<32> bs(i);
		unsigned long long cnt = -1;
		for (int j = 0; j < n; ++j) {
			if (bs.test(j)) cnt &= a[j];
		}
		if (std::bitset<64>(cnt).count() == k) ++ans;
	}
	std::cout << ans << "\n";
}

/* 状态压缩 1 */
inline void solve() {
	int n, k; std::cin >> n >> k;
	std::vector<unsigned long long> a(n);
	for (auto &it : a) std::cin >> it;
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		unsigned long long cnt = -1;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) cnt &= a[j];
		}
		if (__builtin_popcount(cnt) == k) ++ans;
	}
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


