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

int n;

inline void solve() {
  std::cin >> n;

  auto grid = std::vector<std::vector<int> > (n + 1, std::vector<int>(n + 1));
  auto ans = std::vector<std::vector<int> > (n + 1, std::vector<int>(n + 1, INT_MAX));
  auto dir = std::vector<PI>() = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch; std::cin >> ch;
      grid[j][i] = ch - '0';
    }
  }
//
//  for (int i = 1; i <= n; ++i) {
//    for (int j = 1; j <= n; ++j) {
//      std::cout << grid[i][j];
//    }
//    std::cout << "\n";
//  }
//
  int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

//  std::function<void(int, int, int)> DFS = [&](int x, int y, int u) {
//    if (x == x2 && y == y2) { ans = std::max(ans, u); return; }
//    for (int i = 0; i < n; ++i) {
//      auto [dx, dy] = dir[i];
//      x += dx, y += dy;
//      if (1 > x || x > n || 1 > y || y > n) continue;
//      if (vis[y][x]) continue;
//      if (grid[y][x]) continue;
//
//      vis[y][x] = true;
//      DFS(x, y, u + 1);
//      vis[y][x] = false;
//    }
//  };

  auto que = std::queue<std::pair<int, PI> >();

  ans[y1][x1] = 0;
  que.push({0, {x1, y1}});

  while (!que.empty()) {
    auto [v, pi] = que.front(); que.pop();
    auto [xx, yy] = pi;

    for (int i = 0; i < 4; ++i) {
      auto [dx, dy] = dir[i];
      int x = xx + dx, y = yy + dy;

      if (1 > x || x > n || 1 > y || y > n || grid[y][x]) continue;

      if (v + 1 >= ans[y][x]) continue;

      ans[y][x] = v + 1;
      que.push({v + 1, {x, y}});
    }
  }

  std::cout << ans[y2][x2];
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