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
int a[100];
inline void solve() {
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a, a + n);
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (flag) {
			printf("%d ", a[i]);
			flag = false;
		} else {
			std::cout << a[i] << " ";
			flag = true;
		}	
	}
	std::cout << "\n";
	std::cout << a[44];
	printf("%d", a[44]);
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


