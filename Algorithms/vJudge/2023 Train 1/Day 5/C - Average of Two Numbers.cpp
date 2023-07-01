/**
 * https://vjudge.csgrandeur.cn/problem/CSG-1159
 * \category: 
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
// #define ONLINE_JUDGE
using namespace std;
using ll = long long;

inline void solve() {
  int n; while (cin >> n) {
    vector<int> a(n + 1);
    set<int> s;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) { cin >> a[i]; s.insert(a[i]); }
    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if ((a[i] + a[j]) % 2 == 0) {
          int t = (a[i] + a[j])/ 2;
          if (s.count(t)) {
            s.erase((int)t);
            ++ans;
          }
        }
      }
    }
    cout << ans << '\n';
  }
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
