/**
 * @problem: P3371 【模板】单源最短路径（弱化版）
 * @link: https://www.luogu.com.cn/problem/P3371
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 233;

auto edge = std::array<std::vector<PI>, kN>();
auto dis = std::array<int, kN>();

auto heap = std::priority_queue<PI, std::vector<PI>, std::greater<> >();

inline void solve() {
  dis.fill(INT_MAX);
  
  int n, m, s; std::cin >> n >> m >> s;
  while (m--) {
    int x, y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
  }
  
  heap.emplace(0, s);
  dis[s] = 0;
  while (!heap.empty()) {
    auto [d, x] = heap.top(); heap.pop();
    if (d != dis[x]) continue;
    for (auto [y, v] : edge[x]) {
      if (dis[y] > dis[x] + v) {
        dis[y] = dis[x] + v;
        heap.emplace(dis[y], y);
      }
    }
  }
  for (int i = 1; i <= n; ++i) std::cout << dis[i] << " ";
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

