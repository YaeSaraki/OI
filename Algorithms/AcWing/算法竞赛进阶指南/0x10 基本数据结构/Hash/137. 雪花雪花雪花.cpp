#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <array>
#include <deque>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

const int kN = 1e5;
const int kBase = 233;

inline void solve() {
	int m = 6;

	auto a = std::array<std::array<int, 15>, kN>();

	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
			a[i][j + m] = a[i][j];
		}
	}

	auto b = a;

	/** 字符串的最小表示法 */
	auto GetMin = [&](int *s) {
		int i = 0, j = 1;
		while (i < m && j < m) {
			int k = 0;
			while (k < m && s[i + k] == s[j + k]) ++k;
			if (k == m) break;
			if (s[i + k] > s[j + k]) i += k + 1;
			else j += k + 1;
			if (i == j) ++j;
		}
		return std::min(i, j);
	};

	/** get MinExper: m1->positive path & m2->negotive path */
	
	auto m1 = std::array<int, kN>();
	auto m2 = std::array<int, kN>();
	
	for (int i = 0; i < n; ++i) m1[i] = GetMin(a[i].data());
	for (int i = 0; i < n; ++i) {
		std::reverse(b[i].begin(), std::next(b[i].begin(), 2 * m));
		m2[i] = GetMin(b[i].data());
	}

	/** Hash on MinExpr */
	auto s = std::unordered_set<i64>();
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		i64 h1 = 0, h2 = 0;
		for (int j = 0; j < m; ++j) {
			h1 = h1 * kBase + a[i][j + m1[i]];
			h2 = h2 * kBase + b[i][j + m2[i]];
		}
		if (!s.count(h1)) s.emplace(h1);
		else { flag = true; break;  }
		if (h1 == h2) continue;
		if (!s.count(h2)) s.emplace(h2);
		else { flag = true; break;  }
	}
	std::cout << (flag ? "Twin snowflakes found.\n" : "No two snowflakes are alike.\n");
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
