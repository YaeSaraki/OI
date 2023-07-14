/**
 * \link: https://ac.nowcoder.com/acm/contest/61132/H
 * \category: 最短路 
 *
 * \date: 
 * \author: YaeSaraki
 **/

#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
using PI = pair<int, int>;

vector<vector<char> > miniMap;
vector<vector<int> > jumpEngine, point;
vector<pair<int, int> > dis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

inline void solve() {
  /** init. */
  int n, m; cin >> n >> m;
  miniMap = vector<vector<char> >(n + 2, vector<char> (m + 2));
  point = vector<vector<int> >(n + 2, vector<int> (m + 2));
  jumpEngine = vector<vector<int> >(n + 2, vector<int> (m + 2));
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) 
      cin >> miniMap[i][j];
  int num; cin >> num;
  for (int i = 0; i < num; ++i) {
    int y, x, dis; cin >> y >> x >> dis;
    jumpEngine[y][x] = dis;
  }

  /** BFS. */
  queue<PI> que;
  que.push({1, 1});
  while (que.size()) {
    auto now = que.front();
    que.pop();
    int y_now = now.first, x_now = now.second;
    int jump = (jumpEngine[y_now][x_now] ? jumpEngine[y_now][x_now] : 1);
    int step = (jumpEngine[y_now][x_now] == 0 ? 1 : 0);
    for (auto [dx, dy] : dis) {
      int x = x_now + dx * jump;
      int y = y_now + dy * jump;
      if (x < 1 || y < 1 || x > m || y > n) continue;
      if (miniMap[y][x] == '#') continue;
      if (point[y][x] <= point[y_now][x_now] + step && point[y][x]) continue;
      point[y][x] = point[y_now][x_now] + step;
      que.push({y, x});
    }
  }
  if (point[n][m]) cout << point[n][m] << '\n';
  else cout << "-1\n";
  return;
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
