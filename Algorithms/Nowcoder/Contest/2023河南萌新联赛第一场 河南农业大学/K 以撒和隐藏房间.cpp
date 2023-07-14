/**
 * \link:https://ac.nowcoder.com/acm/contest/61132/K
 * \category: 暴力
 *
 * \date: 
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using PI = pair<int, int>;

vector<vector<char> > miniMap;
vector<PI> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isSecretRoom(int y, int x) {
  int normal_room = 0;

  for (auto [dx, dy] : direction) {
    int x_now = x + dx, y_now = y + dy;
    if (miniMap[y_now][x_now] == '2') return false;
    if (miniMap[y_now][x_now] == '1') ++normal_room;
  }
  if (normal_room == 3) return true;
  return false;
}

inline void solve() {
  int n, m; cin >> n >> m;
  miniMap = vector<vector<char> >(n + 2, vector<char> (m + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> miniMap.at(i).at(j);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (miniMap[i][j] == '0' && isSecretRoom(i, j))
        ++ans;
    }
  }

  if (ans) cout << "YES\n" << ans << '\n';
  else cout << "NO\n";
  return ;
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
