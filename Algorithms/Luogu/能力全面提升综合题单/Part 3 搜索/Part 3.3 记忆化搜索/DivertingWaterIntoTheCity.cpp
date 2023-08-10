/**
 * @problem: P1514 [NOIP2010 提高组] 引水入城
 * @link: https://www.luogu.com.cn/problem/P1514
 * @category: 动态规划 dp BFS 记忆化搜索
 * @date: Wed Jul 19 08:40:54 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI = pair<int, int>;

int n, m;
vector<vector<int> > altitude;
vector<vector<bool> > vis;
vector<PI> dis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void BFS(PI start) {
  queue<PI> que;
  que.emplace(start);
  vis[start.second][start.first] = true;
  while (!que.empty()) {
    auto [xx, yy] = que.front(); que.pop();
    for (auto [dx, dy] : dis) {
      int x = xx + dx, y = yy + dy;

      if (x < 0 || m < x || y < 0 || n < y || vis[y][x]) continue;

      if (altitude[y][x] >= altitude[yy][xx]) {
        que.emplace(x, y);
        vis[y][x] = true;
      }
    }
  }
}

inline void solve() {
  cin>> n >> m;
  altitude = vector<vector<int> >(n + 233, vector<int>(m + 233));
  vis = vector<vector<bool> >(n + 233, vector<bool>(m + 233));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> altitude[i][j];
    }
  }
  vector<bool> canReach;
  for (int i = 0;  i < m; ++i) {
    BFS({i, n - 1});
    int cnt = 0;
    for (int j = 0; j < m; ++i)
      if (!vis[j][0])


  }
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
