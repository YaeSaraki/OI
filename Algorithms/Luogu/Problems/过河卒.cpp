/**
 * @problem: P1002 [NOIP2002 普及组] 过河卒
 * @link: https://www.luogu.com.cn/problem/P1002
 * @category: 动态规划
 * @date: Thu Jul 27 10:29:39 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

using ll = long long;
using PI = std::pair<int, int>;

size_t n, m, ans;
PI final, horse;
std::vector<std::vector<char> > grid;
std::vector<std::vector<int> > mem;
std::vector<PI> dir_solider{{1, 0}, {0, 1},};
std::vector<PI> dir_horse{{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};

int DFS(int xx, int yy) {
  if (mem[yy][xx]) return mem[yy][xx];

  for (auto [dx, dy] : dir_solider) {
    int x = xx + dx, y = yy + dy;
    if (x < 0 || m < x ||
        y < 0 || n < y || grid[y][x] == 'H')
      continue;
    if (DFS(x, y)) mem[yy][xx] += mem[y][x];
  }
  return mem[yy][xx];
}

inline void solve() {
  std::cin >> final.first >> final.second >>
              horse.first >> horse.second;
  n = final.second, m = final.first;
  mem = std::vector<std::vector<int> > (n + 1, std::vector<int> (m + 1));
  grid = std::vector<std::vector<char> > (n + 1, std::vector<char> (m + 1));

  /* set the horse site */
  int xx = horse.first, yy = horse.second;
  grid[yy][xx] = 'H';
  for (auto [dx, dy] : dir_horse) {
    int x = xx + dx, y = yy + dy;
    if (x < 0 || m < x ||
        y < 0 || n < y) continue;
    grid[y][x] = 'H';
  }

  /* set final */
  grid[final.second][final.first] = 'F';
  mem[final.second][final.first] = 1;

  /* start dfs at solider */
  std::cout << DFS(0, 0) << '\n';

#ifdef DEBUG
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      std::cout << (grid[i][j] == '\0' ? 0 : 1);
    }
    std::cout << '\n';
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      std::cout << mem[i][j];
    }
    std::cout << '\n';
  }
#endif
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
