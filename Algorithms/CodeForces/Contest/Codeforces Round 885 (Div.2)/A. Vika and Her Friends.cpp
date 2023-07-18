/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @author: YaeSaraki
 **/
#pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <vector>
#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

inline void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<bool> > a(n + 233, vector<bool>(m + 233));
  int x_s, y_s; cin >> x_s >> y_s;
  double kk = (double)y_s / x_s;
  bool flag = true;
  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y;
    if ((double)y / x == kk || (double)y / x == -kk) flag = false;
    a[y][x] = true;
  }
  if (!flag) return cout << "NO\n", void();
  vector<pair<int, int> > dis = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int time = 0;
  for (auto [dx, dy] : dis) {
    int x = x_s + dx * 2, y = y_s + dy * 2;
    if (x < 1 || y < 1 || x > m || y > n) continue;
    if (a[y][x]) return cout << "NO\n", void();
  }
  if (time) flag = false;
  if (flag) cout << "YES\n";
  else cout << "NO\n";
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
