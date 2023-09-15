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
#include <string>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

std::string str;
auto grid = std::vector<std::vector<int> >();
auto dir = std::vector<PI>() = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                                                  {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int ans = 0;
auto DFS(int x, int y, int k, int idx) {
  if (idx == str.length()) ++ans;
  if (str[idx] != grid[y][x]) return;
  auto [dx, dy] = dir[k];
  DFS(x + dx, y + dy, k, idx + 1);
}

inline void solve() {
  std::cin >> str;
  int r, c; std::cin >> r >> c;
  grid = std::vector<std::vector<int> >(r, std::vector<int>(c));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      std::cin >> grid[i][j];

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (str[0] != grid[i][j]) continue;
      for (int k = 0; k < 8; ++k) {
        DFS(i, j, k, 1);
      }
    }
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
