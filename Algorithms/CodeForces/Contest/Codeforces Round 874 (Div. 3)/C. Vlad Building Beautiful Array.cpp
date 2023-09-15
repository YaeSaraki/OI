/**
 * \link: https://codeforces.com/contest/1833/problem/C
 * \category: greedy math *800
 * 
 * 
 * 
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

inline void solve() {
  int n; cin >> n;
  int minn = 1e9;
  vector<int> a(n);
  bool flag_odd = 0, flag_even = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] & 1) minn = min(minn, a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    if (i == n) flag_odd = true;
    if (a[i] & 1) continue;
    if (a[i] > minn) continue;

    break;
  }
  if (!flag_odd) {
    for (int i = 0; i <= n; ++i) {
      if (i == n) flag_even = true;
      if (!(a[i] & 1)) continue;
      if (a[i] > minn) continue;
      break;
    }
  }
  if (flag_odd || flag_even) cout << "YES\n";
  else cout << "NO\n";
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}