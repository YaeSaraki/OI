/**
 * @problem: P1443 马的遍历
 * @link: https://www.luogu.com.cn/problem/P1443
 * @category: BFS 
 * @date:
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using PI = pair<int, int>;

int n, m;

vector<vector<int>> ans;
vector<vector<bool> > vis;

struct State {
  int x, y, step = 0;
};

void DFS(State start) {
  ans = vector<vector<int>>(n, vector<int>(m, -1));
  vis = vector<vector<bool>>(n, vector<bool>(m));
  vector<PI> dis = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
  queue<State> que;
  que.push(start);
  ans[start.y][start.x] = 0;
  vis[start.y][start.x] = true;
  while (que.size()) {
    State now = que.front();
    que.pop();
    int x = now.x, y = now.y, s = now.step + 1;
    for (auto [dx, dy] : dis) {
      int x_next = x + dx, y_next = y + dy;
      if (x_next < 0 || m <= x_next ||
          y_next < 0 || n <= y_next ||
          vis[y_next][x_next]) {
        continue;
      }
      ans[y_next][x_next] = s;
      vis[y_next][x_next] = true;
      que.push({x_next, y_next, s});
    }
  } 
}

inline void solve() {
  cin >> n >> m;
  State start; cin >> start.y >> start.x;
  --start.x, --start.y;
  DFS(start);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%-5d", ans[i][j]);
    }
    printf("\n");
  }
}

bool rt = false;
signed main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}