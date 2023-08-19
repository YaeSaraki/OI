/**
 * @problem: P1339 [USACO09OCT] Heat Wave G
 * @link: https://www.luogu.com.cn/problem/P1339
 * @category: 
 * @date: 
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <array>
#include <queue>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 6500 * 2;
auto edge = std::array<std::vector<PI>, kN>();
auto heap = std::priority_queue<PI, std::vector<PI>, std::greater<PI> >();
auto vis = std::array<bool, kN>();
auto dis = std::array<int, kN>();
auto cnt = std::array<int, kN>();

inline void solve() {
  dis.fill(INT_MAX);
  
  int n, m, s, t; std::cin >> n >> m >> s >> t;
  while (m--) {
    int x,  y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
    edge[y].emplace_back(x, v);
  }

  dis[s] = 0;
  heap.emplace(0, s);
  while (!heap.empty()) {
    auto [v, x] = heap.top(); heap.pop();
    vis[x] = false;
    for (auto [y, v] : edge[x]) {
      if (dis[y] > dis[x] + v) {
        dis[y] = dis[x] + v;
        cnt[y] = cnt[x] + 1;
        if (cnt[y] >= n) break;
        if (!vis[y]) heap.emplace(dis[y], y), vis[y] = true;
      }
    }
  }
  std::cout << dis[t];
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
