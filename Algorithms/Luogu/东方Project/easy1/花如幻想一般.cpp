/**
 * @problem: P8537 「Wdoi-2」花如幻想一般
 * @link: https://www.luogu.com.cn/problem/P8537
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
// #define int long long

#define ONLINE_JUDGE

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  auto a = std::vector<int>(n);
  auto correct = std::vector<int>(n);
  for (auto &it : a) std::cin >> it;
  for (auto &it : correct) std::cin >> it;
  auto b = a;
  std::reverse(ALL(b));
  int cnt1 = 0, cnt2 = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != correct[i]) ++cnt1;
    if (b[i] != correct[i]) ++cnt2;
  }
  std::cout << std::min(cnt1, cnt2);
}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  // freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}


