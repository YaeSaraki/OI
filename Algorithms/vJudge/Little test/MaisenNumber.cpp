/**
 * @problem: P1045 [NOIP2003 普及组] 麦森数
 * @link: https://www.luogu.com.cn/problem/P1045
 * @category: math 高精度
 * @date:
 * @Author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
#include <cmath>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

std::vector<int> sub(std::vector<int> &a, std::vector<int> &b) {
	/* A >= B */
	int t = 0;
	std::vector<int> c;
	for (int i = 0; i < a.size(); ++i) {
		t = a[i] - t;
		if (i < b.size()) t -= b[i];
		c.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

/** 高精度 * 高精度 */
std::vector<int> mul(std::vector<int> &a, std::vector<int> &b) {
	int t = 0;
	std::vector<int> c(500);
	/* 丢弃高于501位的数 */
	for (int i = 0; i < std::min((int)a.size(), 500); ++i) {
		for (int j = 0; j < std::min((int)b.size(), 500); ++j) {
			if (i + j < 500) c[i + j] += a[i] * b[j];
		}
	}
	/* 进位处理 */
	for (int i = 0; i < c.size(); ++i) {
		if (c[i] > 9) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	while (c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

/* 快速幂 */
std::vector<int> qPow(std::vector<int> &a, int n) {
	std::vector<int> ans = {1};
	while (n) {
		if (n & 1) ans = mul(ans, a);
		a = mul(a, a);
		n >>= 1;
	}
	return ans;
}

inline void solve() {
	int n; std::cin >> n;
	std::vector<int> a = {2};

#ifdef dbg_mul_function
	std::vector<int> dbg_temp = {1};
	a = mul(a, dbg_temp);
	for (auto it : a) std::cout << it;
	std::cout << " ";

#endif

#ifdef dbg_pow_funtion
	for (auto it : a) std::cout << it;
	std::cout << " ";
	a = qPow(a, 2);
	for (auto it : a) std::cout << it;
	std::cout << " ";
#endif

	/* 快速幂求2 ^ n */
	a = qPow(a, n);

	/* 减去1 */
	std::vector<int> b = {1};
	a = sub(a, b);

	/* 处理 位数 */
	while (a.size() != 500) {
		while (a.size() > 500) a.pop_back();
		while (a.size() < 500) a.push_back(0);
	}

	/* 输出位数 */
	std::cout << (int)(log10(2) * n) + 1 << '\n';

	/* 逆序输出 */
	for (int i = 499; ~i; --i) {
		std::cout << a[i];
		if (i % 50 == 0) std::cout << "\n";
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


