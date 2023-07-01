/**
 * https://ac.nowcoder.com/acm/contest/17148/A
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

int a[1001][1001];
using namespace std;

inline void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  // for (int i = 0; i < n; ++i) {
  //     for (int j = 0; j < m; ++j) {
  //       cout << a[i][j];
  //     }
  //     cout << endl;
  //   }
  int h, w; cin >> h >> w;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // if (i + h - 1 < n && j + w - 1 < m) {
      if (i + h - 1 > n || j + w - 1 > m) continue;
      if ((a[i][j] == a[i + h - 1][j]) && a[i][j] == a[i + h - 1][j + w - 1] &&
          a[i][j] == a[i][j + w - 1]) {
        //							cout <<
        // i << " " << j; 							cout<<a[j][i]<<" ";
        // cout << a[j + w - 1][i + h - 1] << " ";
        return cout << "YES\n", void();
      }
          // }
    }
  }
  return cout << "NO\n", void();
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