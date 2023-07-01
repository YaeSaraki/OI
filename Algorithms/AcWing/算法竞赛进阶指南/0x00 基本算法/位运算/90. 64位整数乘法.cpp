/**
 * \link: https://www.acwing.com/problem/content/92/
 * \category: 位运算
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

inline void solve() {
  ull a, b, p; cin >> a >> b >> p;
  ull cnt = 0;
  while (b) {
    if (b & 1) cnt = (cnt + a) % p;
    b >>= 1;
    a = (a + a) % p;
  }
  cout << cnt << '\n';
  return ;
}

void solve2() {
  ull a, b, p; cin >> a >> b >> p;
  cout << (ull)((__int128)(a * b) % p);
}


bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}