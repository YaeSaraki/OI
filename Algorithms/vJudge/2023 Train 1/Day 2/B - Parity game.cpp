/**
 * https://vjudge.csgrandeur.cn/contest/558623#problem/B
 * \category: 并查集
 * 
 * 
 * ? State: Attemped
*/
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

bitset<1000000001> str, is;

inline void solve() {
  int n; cin >> n;
  int q; cin >> q;
  char opt[20];
  for (int i = 1; i <= q; ++i) {
    int l, r; cin >> l >> r;
    cin >> opt;
    for (int j = l; j <= r; ++j) {
      if (!is[j]) {
        is[j] = 1;
        if (opt[0] == 'e') str[j] = 0;
        else str[j] = 1;
      } else if (str[j] == 1) {
        if (opt[0] == 'e') return cout << i - 1 << '\n', void();
        if (opt[0] == 'o') continue;
      } else {
        if (opt[0] == 'e') continue;
        if (opt[0] == 'o') return cout << i - 1 << '\n', void();
      }
    }
  }
  return cout << q << '\n', void();
}

bool rt = 0;
signed main () {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}