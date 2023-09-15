/**
 * @problem: P8469 [Aya Round 1 D] 文文的数学游戏
 * @link: https://www.luogu.com.cn/problem/solution/P8469
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

#define ONLINE_JUDGE

using i64 = long long;
using PI = std::pair<int, int>;

const int MOD = 1000000000 + 7;

inline void solve() {
  int n; std::cin >>n;
  auto a = std::vector<int>(n);
  int min = INT_MAX;
  for (auto &it : a) std::cin >> it, min = std::min(min, it);
  i64 ans = 1;
  for (auto it : a) ans = (i64)(ans * (it / min) % MOD);
  std::cout << min << " " << ans << "\n";
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


