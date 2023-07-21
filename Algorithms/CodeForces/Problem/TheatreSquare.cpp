/**
 * @problem: A. Theatre Square
 * @link: https://codeforces.com/problemset/problem/1/A
 * @category: math
 * @date: Tue Jul 18 22:23:35 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

inline void solve() {
  int n, m, a; cin >> n >> m >> a;
   ll ans = (ll)ceil(n * 1.0 / a) * (ll)ceil(m * 1.0 / a);
  cout << ans << '\n';
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
