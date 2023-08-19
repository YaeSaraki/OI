/**
 * @problem: P7939 「Wdcfr-1」Alice Wins! (easy version)
 * @link: https://www.luogu.com.cn/problem/P7939
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

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  auto a = std::vector<int>(2 * n);
  auto b = std::vector<int>(2 * n);

  for (auto &it : a) std::cin >> it;
  for (auto &it : b) std::cin >> it;

  for (int i = 0, chance = n; i < 2 * n; ++i) {
    /* when a[i] won, the b[i] should equal to t. (a[i] - 1 + 1) % 3 + 1 */
    int t = a[i] % 3 + 1;
    if (b[i] == t) continue;
    if (chance) {
      b[i] = t, --chance;
      continue;
    }

    /* when the chance isn't enough, should change a[i] equal to t. */
    t = (b[i] + 1) % 3 + 1;
    a[i] = t;
  }
  std::cout << n + n << "\n";
  for (auto it : a) std::cout << it << " ";
  std::cout << "\n";
  for (auto it : b) std::cout << it << " ";
  std::cout << "\n";
}

bool rt = true;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}

