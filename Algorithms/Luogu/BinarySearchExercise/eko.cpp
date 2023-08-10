/**
 * @problem: P1873 [COCI2011-2012#5] EKO / 砍树
 * @link: https://www.luogu.com.cn/problem/P1873
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int n, k;
std::vector<int> high;

bool check(int mid) {
	int val = 0;
	for (int i = 0; i < n; ++i) {
		if (high[i] > mid) val += high[i] - mid;
	}
	if (val >= k) return true;
	else return false;
}

inline void solve() {
	std::cin >> n >> k;
	high = std::vector<int> (n);
	int lo = 0, hi = 0;
	for (auto &it : high) {
		std::cin >> it;
		hi = std::max(hi, it);
	}

	while (lo <= hi) {
		int mid = lo + ((hi - lo) >> 1);
		if (check(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	std::cout << hi << '\n';
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


