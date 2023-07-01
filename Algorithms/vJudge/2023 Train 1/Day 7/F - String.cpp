/**
 * \link: https://vjudge.csgrandeur.cn/problem/HDU-6572
 * \category: 数学 乘法原理
 * 
 * 
 * 
*/
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;
#define int long long

inline void solve() {
  int n; while (cin >> n) {
    string str; cin >> str;
    int aa = 0, vv = 0, ii = 0, nn = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == 'a') ++aa;
      else if (str[i] == 'v') ++vv;
      else if (str[i] == 'i') ++ii;
      else if (str[i] == 'n') ++nn;
    }
    int ans = aa * vv * ii * nn;
    int y = pow(n, 4);
    int cnt = __gcd(ans, y);
    cout << (ans / cnt) << '/' << (y / cnt) << '\n';
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