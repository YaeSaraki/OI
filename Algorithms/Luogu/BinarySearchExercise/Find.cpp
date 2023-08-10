/**
 * @problem: P2249 【深基13.例1】查找
 * @link: https://www.luogu.com.cn/problem/P2249
 * @category: BinarySearch
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
	int n, q; std::cin >> n >> q;
	std::vector<PI> nums(n);
	int maxx = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> nums[i].first;
		nums[i].second = i + 1;
		maxx = std::max(maxx, nums[i].first);
	}
	while (q--) {
		int x; std::cin >> x;
		/** 二分 */
		int lo = 0, hi = n;
		while (lo < hi) {
			int mid = lo + ((hi - lo) >> 1);
			if (x <= nums[mid].first) hi = mid;
			else lo = mid + 1;
		}

		if (nums[lo].first == x) std::cout << nums[lo].second << " ";
		else std::cout << "-1 ";
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


