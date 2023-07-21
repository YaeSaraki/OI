/**
 * @problem: P3956 [NOIP2017 普及组] 棋盘
 * @link: https://www.luogu.com.cn/problem/P3956
 * @category: BFS/DFS 最短路
 * @date: Tue Jul 18 15:24:58 CST 2023
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using TP = tuple<int, int, int, int>;

int n, m;
vector<vector<int> > grid;
vector<vector<int> > minm;

void BFS(TP start) {
  queue<TP> que;
  vector<pair<int, int> > dis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  que.push(start);
  while (que.size()) {
    auto [xx, yy, cc, mm] = que.front(); que.pop();
    

    for (auto [dx, dy] : dis) {
      int x = xx + dx, y = yy + dy;

      if (x < 1 || m < x || y < 1 || m < y || mm >= minm[y][x]) continue;

      if (grid[yy][xx] != 0 && grid[y][x] == 0) {
        minm[y][x] = min(minm[y][x],mm + 2);
        que.push({x, y, cc, mm + 2});
        continue;
      }

      if (grid[y][x] == 0) continue;

      if (grid[y][x] != cc) {
        minm[y][x] = min(minm[y][x],mm + 1);
        que.push({x, y, grid[y][x], mm + 1});
      } else {
        minm[y][x] = min(minm[y][x],mm);
        que.push({x, y, cc, mm});
      }
    
    } 
  }    
}

inline void solve() {
  cin >> m >> n;
  grid = vector<vector<int> >(m + 1, vector<int> (m + 1));
  minm = vector<vector<int> > (m + 1, vector<int> (m + 1, INT_MAX));
  minm[1][1] = 0;
  while (n--) {
    int x, y, c; cin >> y >> x >> c;
    if (c == 0) c = 2;
    grid[y][x] = c;
  }
  BFS({1, 1, grid[1][1], 0});

  // for (int i = 1; i <= m; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     int t = minm[i][j];
  //     cout << (t == INT_MAX ? 0 : t) << " ";
  //   }
  //   cout << '\n';
  // }

  int x = minm[m][m];
  cout << (x == INT_MAX ? -1 : x) << '\n';
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
