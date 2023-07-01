/**
 * \link: https://vjudge.csgrandeur.cn/problem/HDU-6576
 * \category: gcd lcm
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
#define int ll
inline void solve() {
  int n, m; while(cin >> n >> m) {
    vector<int> a(n + 1);
    for (int i = 0; i < n ; ++i) cin >> a[i];
    vector<int> b(n + 1);

    int getgcd = b[0] = a[0];
    for (int i = 1; i < n ; ++i) {
      getgcd = getgcd * a[i] / __gcd(getgcd, a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      b[i] = getgcd / a[i];
      sum += b[i];
    }
    if (m % sum == 0) { 
      cout << "Yes\n";
      int x = m / sum;
      for (int i = 0; i < n - 1; ++i) cout << b[i] * x << " ";
      cout << b[n - 1] * x << '\n';
    } else cout << "No\n"; 
  }
  return;
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