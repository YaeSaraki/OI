/**
 * @problem: P8444 不等价交换法则
 * @link: https://www.luogu.com.cn/problem/P8444
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  auto items = std::vector<int>(n);
  for (auto &it : items) std::cin >> it;
  int volume; std::cin >> volume;
  std::sort(ALL(items));
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (items[mid] > volume) hi = mid;
    else lo = mid + 1;
  }
  volume = items[lo];
  // DBG(volume);
  int ans = 0;
  for (int i = 0; i < lo && volume >= items[i]; ++i) volume -= items[i], ++ans;
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




