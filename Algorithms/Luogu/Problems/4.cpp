/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <queue>
#include <climits>

#define ONLINE_JUDGE

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;


inline void solve() {
  int n; std::cin >> n;
  auto a = std::vector<int>(n);
  for (auto &it : a) std::cin >> it;
  auto l = std::vector<int>(n);
  auto que = std::queue<int>();
  que.emplace(INT_MAX);
  for (int i = 0; i < n; ++i) {
    while (que.front() <= a[i]) que.pop();
    l[i] = que.size() - 1;
    que.emplace(a[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += l[i];
  }
  std::cout << ans;

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
