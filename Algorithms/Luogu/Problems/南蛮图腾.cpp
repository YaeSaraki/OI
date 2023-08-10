/**
 * @problem: P1498 南蛮图腾
 * @link: https://www.luogu.com.cn/problem/P1498
 * @category: 字符串 递归 分治 深度优先搜索 DFS
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

const int kN = 1111;
std::array<std::array<char, kN>, kN> grid;

inline void solve() {
  int n; std::cin >> n;
  for (auto &it : grid) it.fill(' ');
  grid[2] = {' ', ' ', '/', '\\', ' '};
  grid[1] = {' ', '/', '_', '_', '\\'};

  int x = 4, y = 2;
  while (--n) {
    /* 复制 -> 左侧 */
    int start_x = x + 1, end_x = x + x;
    for (int i = 1; i <= y; ++i) {
      for (int j = start_x; j <= end_x; ++j) {
        grid[i][j] = grid[i][j - x];
      }
    }

    /* 复制 -> 上侧 */
    start_x = x - (x >> 1) + 1, end_x = x + (x >> 1);
    int start_y = y + 1, end_y = y + y;
    for (int i = start_y; i <= end_y; ++i) {
      for (int j = start_x; j <= end_x; ++j) {
        grid[i][j] = grid[i - y][j - (x >> 1)];
      }
    }

    /* 更新 x, y */
    x += x, y += y;
  }


  for (int i = y; i; --i) {
    for (int j = 1; j <= x; ++j) {
      std::cout << grid[i][j];
    }
    std::cout << '\n';
  }
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
