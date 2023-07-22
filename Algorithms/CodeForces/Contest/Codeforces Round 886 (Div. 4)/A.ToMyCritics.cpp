/**
 * @problem: A. To My Critics
 * @link: https://codeforces.com/contest/1850/problem/A
 * @category: implementation sortings
 * @date:
 * @Author:
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
using PI = pair<int, int>;

inline void solve() {
  int a, b, c; cin >> a >> b >> c;
  cout <<  ((a + b + c) - min({a, b, c}) >= 10 ? "YES\n" : "NO\n");
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
