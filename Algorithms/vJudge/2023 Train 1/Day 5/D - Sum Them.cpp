/**
 * https://vjudge.csgrandeur.cn/problem/CSG-1160
 * \category: 阶乘 逆元
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int n, m;


inline void solve() {
  while (cin >> n >> m) {
    vector<ll> inv(n + m + 1);

    // todo inv init 
    inv[0] = inv[1] = 0; // new :  逆元线性筛
    for (int i = 2; i < n + m + i; ++i) 
      inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    // todo inv init end
  
    ll res = 1, ans = 0;
    for (int i = 1; i <= m; ++i) res = res * i % MOD;
    ans += res;
    for (int i = 2; i <= n; ++i) {
      res = res * inv[i - 1] % MOD * (i + m - 1) % MOD;
      ans = (ans + res) % MOD;
    }
    cout << ans << '\n';
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