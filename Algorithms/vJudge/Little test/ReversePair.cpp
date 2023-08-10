/**
 * @problem: P1908 逆序对
 * @link: https://www.luogu.com.cn/problem/P1908
 * @category: sort 递归
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

const int kN = 5e5 + 233;
int a[kN], temp[kN];

int ans = 0;
void merge(int *a, int a_len, int *b, int b_len, int *c) {
	size_t i = 0, j = 0, k = 0;
	while (i < a_len && j < b_len) {
		if (b[j] < a[i]) {
			c[k] = b[j];
			ans += a_len - i;
			++j;
		} else {
			c[k] = a[i];
			++i;
		}
		++k;
	}
	while (i < a_len) c[k++] = a[i++];
	while (j < b_len) c[k++] = b[j++];
}

void mergeSort(int *a, int left, int right) {
	if (right - left <= 1) return;
	int mid = left + ((right - left) >> 1);
	mergeSort(a, left, mid), mergeSort(a, mid, right);
	merge(a + left, mid - left, a + mid, right - mid, temp + left);
	for (int i = left; i < right; ++i) a[i] = temp[i];
}

inline void solve() {
	ans = 0;
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	mergeSort(a, 0, n);
	std::cout << ans << '\n';
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


