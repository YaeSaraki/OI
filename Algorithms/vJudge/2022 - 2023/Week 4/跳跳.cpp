/**
 * @problem: B - 跳跳！
 * @link: https://www.luogu.com.cn/problem/P4995
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

inline void solve() {
  int n; std::cin >> n;
  std::vector<int> high(n);
  for (auto &it : high) std::cin >> it;
  std::sort(ALL(high));
  bool up = true;
  int lo = 0, hi = n - 1;
  int energy = 0, now_high = 0;
  while (lo <= hi) {
     if (up) {
       int need_energy = (high[hi] - now_high) * (high[hi] - now_high);
       energy += need_energy;
       now_high = high[hi];
       up = false;
       --hi;
     } else {
       int need_energy = (now_high - high[lo]) * (now_high - high[lo]);
       energy += need_energy;
       now_high = high[lo];
       up = true;
       ++lo;
     }
  }
  std::cout << energy << '\n';
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

#ifdef OLD
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;
int a[100100];
int main() {
	ll ans = 0;
	a[0] = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a, a + n + 1);
	int l = 0, r = n;
	int up = 1;
	while (l < r) {
		if (up) {
			up = 0;
			ans += pow(a[r] - a[l++], 2);
		} else {
			up = 1;
			ans += pow(a[r--] - a[l], 2); 
		}
	}
	cout << ans;
	return 0;
}
#endif