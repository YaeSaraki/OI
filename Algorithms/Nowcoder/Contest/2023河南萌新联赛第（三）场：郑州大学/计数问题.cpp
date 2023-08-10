/**
 * @problem: 计数问题
 * @link: https://ac.nowcoder.com/acm/contest/62332/C
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

inline void solve() {
  int x; std::cin >> x;

  std::vector<int> data(kN);
  for (int i = 1; i < kN; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      /* i 因子 的 个数 */
      if (i % j == 0) data[i] += 2;
      if (j * j == i) --data[i];
    }
  }
  int ans = 0;
  for (int i = 1; i < x; ++i) {
    ans += data[i] * data[x - i];
  }
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
