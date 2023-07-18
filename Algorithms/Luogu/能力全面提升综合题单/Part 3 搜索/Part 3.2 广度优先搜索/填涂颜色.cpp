/**
 * @problem: P1162 填涂颜色
 * @link: https://www.luogu.com.cn/problem/P1162
 * @category: BFS
 * @date: Tue Jul 18 10:50:10 CST 2023
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

int n;
vector<vector<int> > grid;
vector<pair<int, int> > dis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void BFS(int x, int y) {
  queue<pair<int, int> > que;
  if (grid[y][x] == 0 || grid[y][x] == 3) {
    grid[y][x] = 3;
    for (auto [dx, dy] : dis) {
      int x_now = x + dx, y_now = y + dy;
      if (x_now < 0 || n <= x_now || y_now < 0 || n <= y_now) continue;
      if (grid[y_now][x_now] == 0) {
        grid[y_now][x_now] = 3;
        BFS(x_now, y_now);
      }
    }
  }
}

inline void solve() {
  cin >> n ;
  grid = vector<vector<int> > (n, vector<int> (n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    BFS(0, i), BFS(n - 1, i);
    BFS(i, 0), BFS(i, n - 1);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int t = grid[i][j];
      if (t == 3) cout << "0 ";
      if (t == 1) cout << "1 ";
      if (t == 0) cout << "2 ";
    }
    cout << '\n';
  }
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
