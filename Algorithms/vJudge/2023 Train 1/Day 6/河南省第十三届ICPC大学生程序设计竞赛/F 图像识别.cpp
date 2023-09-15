/**
 * https://ac.nowcoder.com/acm/contest/17148/F
 * \category: 坐标 模拟
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

char a[1001][1001];
using namespace std;

inline void solve() {
  int m, n; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
      cin >> a[i];
  }
  int x, y, xx, yy;
  for (int i = 0; i <n ; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#') x = j, y = i;
      if (a[i][j] == '*' && ((a[i + 1][j] == '*' && a[i][j + 1] == '*') ||
          (a[i - 1][j] == '*' && a[i][j - 1] == '*')))
        xx = j, yy = i;
    }
  }
  cout << x - xx << " " << yy - y << '\n';
  return ;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}