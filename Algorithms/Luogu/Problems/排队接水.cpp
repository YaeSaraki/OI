/**
 * @problem: P1223 排队接水
 * @link: https://www.luogu.com.cn/problem/P1223
 * @category: greedy sort
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  std::vector<PI> peo(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> peo[i].first;
    peo[i].second = i + 1;
  }
  std::sort(ALL(peo));

  for (auto it : peo) std::cout << it.second << " ";
  std::cout << "\n";

  double ans = 0;
  std::vector<int> sum(n);
  for (int i = 1; i < n; ++i) {
    sum[i] = sum[i - 1] + peo[i - 1].first;
    ans += sum[i];
  }
  std::cout << std::fixed << std::setprecision(2) << ans / n << '\n';
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
