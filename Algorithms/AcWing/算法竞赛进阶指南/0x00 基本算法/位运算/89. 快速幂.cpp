/**
 * \link: https://www.acwing.com/problem/content/91/
 * \category: 位运算 快速幂
 * 
 * 
 * 
*/

#include <iostream>

using namespace std;
using ll = long long;

ll MyPow(ll a, ll b, ll p) {
  ll cnt = 1 % p;
  while (b) {
    if (b & 1) cnt = cnt * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return cnt;
}

inline void solve() {
  ll a, b, p; cin >> a >> b >> p;
  cout << MyPow(a, b, p);
  return ;
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