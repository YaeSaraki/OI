#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <numeric>
#include <cmath>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

#define ONLINE_JUDGE

using i64 = int64_t;
using PI = std::pair<int, int>;


const int kN = 1e6  + 233;

bool prime(int x) {
	if (x < 2) return false;
	int t = std::sqrt(x);
	for (int i = 2; i < t + 1; ++i) {
		if (x % i == 0) return false; 
	}
	return true;
}

inline void solve() {
	auto isPrime = std::vector<int>(kN);
	for (int i = 0; i < kN; ++i) {
		if (prime(i)) isPrime[i] = 1;
	}
	auto sum = std::vector<int>(kN);
	std::partial_sum(ALL(isPrime), sum.begin());
//     for (int i = 0; i < kN; ++i) std::cout << isPrime[i] << " ";
	int t; std::cin >> t;
	while (t--) {
		int left, right; std::cin >> left >> right;
		std::cout << sum[right] - sum[left - 1] << "\n";
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
