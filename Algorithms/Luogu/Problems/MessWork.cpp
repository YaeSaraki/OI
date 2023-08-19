/**
 * @problem: P1113 杂务
 * @link: https://www.luogu.com.cn/problem/P1113
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <queue>


#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 1e5 + 233;

auto edge = std::array<std::vector<int>, kN>();
auto incoming = std::array<int, kN>();
auto que = std::queue<int>();
auto cnt = std::array<int, kN>();
auto times = std::array<int, kN>();

inline void solve() {
  int n; std::cin >> n;
  /* input. */
  for (int i = 1; i <= n; ++i) {
    int y; std::cin >> y >> times[i];
    int x; while (std::cin >> x, x) {
      edge[x].emplace_back(y);
      ++incoming[y];
    }
  }

  /* find the no incoming node. */
  for (int i = 1; i <= n; ++i)
    if (incoming[i] == 0) que.emplace(i), cnt[i] = times[i];
  while (!que.empty()) {
    int x = que.front(); que.pop();
    for (int y : edge[x]) {
      --incoming[y];
      cnt[y] = std::max(cnt[y], cnt[x] + times[y]);
      if (incoming[y] == 0) que.emplace(y);
    } 
  }
  std::cout << (que.empty() ? *std::max_element(cnt.begin() + 1, cnt.begin() + 1 + n) : -1);
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

