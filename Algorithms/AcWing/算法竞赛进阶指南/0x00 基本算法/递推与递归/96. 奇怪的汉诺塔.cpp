/**
 * \link: https://www.acwing.com/problem/content/98/
 * \category: 递归
 * 
 * 
 * 
*/
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int kN = 13;
int f[kN], d[kN];

inline void solve() {
  f[1] = 1;
  for (int i = 2; i <= 12; ++i) f[i] = 1 + f[i - 1] * 2;
  memset(d, 0x3F, sizeof d);
  d[0] = 0;
  for (int i = 1; i <= 12; ++i) {
    for (int j = 0; j < i; ++j) {
      d[i] = min(d[i], d[j] * 2 + f[i - j]);
    }
  }
  for (int i = 1; i <= 12; ++i) cout << d[i] << "\n";
  return;
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