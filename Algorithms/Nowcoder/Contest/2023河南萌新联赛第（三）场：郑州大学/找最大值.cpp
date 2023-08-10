/**
 * @problem: 找最大值
 * @link: https://ac.nowcoder.com/acm/problem/255585
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n), odds;
  for (auto &it : a) std::cin >> it;
  std::copy_if(ALL(a), std::back_inserter(odds), [](const int i) { return i & 1; });
  std::cout << *max_element(ALL(odds));
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

