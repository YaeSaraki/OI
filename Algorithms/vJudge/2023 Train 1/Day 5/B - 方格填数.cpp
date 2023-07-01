/**
 * https://vjudge.csgrandeur.cn/problem/CSG-1158
 * \category: 
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

inline void solve() {
  int m, n, r, c, x; while (cin >> m >> n >> r >> c >> x) {
    int p1 = (r * c) - 1;
    int p2 = (n - r + 1) * (m - c + 1) - 1;
    if (p1 > x - 1 || p2 > (n * m - x)) cout << "No\n";
    else cout << "Yes\n";
  }
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