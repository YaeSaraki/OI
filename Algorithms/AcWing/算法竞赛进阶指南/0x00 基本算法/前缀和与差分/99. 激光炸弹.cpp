/**
 * @problem: 99. 激光炸弹
 * @link: https://www.acwing.com/problem/content/101/
 * @category: 二维 前缀和
 * @date: No complement
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

const int kN = 5e3 + 2;

inline void solve() {
  int n, r; std::cin >> n >> r;
  r = std::min(r, 5001);
  std::vector<std::vector<int> > grid(kN, std::vector<int> (kN));
  int max_x = 0, max_y = 0;
  while (n--) {
    int x, y, value; std::cin >> x >> y >> value;
    /* 必须是 += 因为可能一个点有多个目标 */
    grid[++y][++x] += value;
    max_x = std::max(max_x, x);
    max_y = std::max(max_y, y);
  }

  /*
   * Q: 如何处理网格边界
   * A: 把坐标值全部加一就好
   */

  for (int i = 1; i < max_y; ++i) {
    for (int j = 1; j < max_x; ++j) {
      grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
    }
  }

  int ans = 0;
  for (int i = r; i <= max_y; ++i) {
    for (int j = r; j <= max_x; ++j) {
      ans = std::max(ans, grid[i][j] - grid[i - r][j] - grid[i][j - r] + grid[i - r][j - r]);
    }
  }

  std::cout << ans << "\n";
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
