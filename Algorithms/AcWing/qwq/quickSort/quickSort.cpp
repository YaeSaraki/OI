/**
 * @problem:
 * @link:
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

using ll = long long;
using PI = std::pair<int, int>;

const int kN = 1e5 + 233;
int a[kN];

void quickSort(int *a, int length) {
	if (length <= 1) return;
	int pivot = a[rand() % length];
	int i = 0, j = 0, k = length;
	while (i < k) {
		if (a[i] < pivot) std::swap(a[i++], a[j++]);
		else if (a[i] > pivot) std::swap(a[i], a[--k]);
		else ++i;
	}
	quickSort(a, j), quickSort(a + k, length - k);
}


inline void solve() {
	int n; std::cin >> n;
	quickSort(a, n);
	for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
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


