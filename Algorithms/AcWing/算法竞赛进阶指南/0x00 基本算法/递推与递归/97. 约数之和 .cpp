#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned ll;

ull myPow(ull base, ull y) {
  ull res = 1;
  while (y) {
    if (y & 1) res *= base;
    base *= base;
    y >>= 1;
  }
  return res;
}

inline void solve() {
  
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