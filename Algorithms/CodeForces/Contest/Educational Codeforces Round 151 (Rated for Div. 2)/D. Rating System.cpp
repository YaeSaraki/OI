/**
 * \link: https://codeforces.com/contest/1845/problem/D
 * \category: binary search brute force data structures dp dsu greedy math two pointers
 * 
 * 
 * * after contest
*/
#include <iostream>
#include <algorithm>
// #define ONLINE_JUDGE
using namespace std;
using ll = long long;

void inline solve() {
  int n; cin >> n;
  ll ans(0), cnt(0), delta(0), maxx(0), sum(0);  
  for (int i = 0; i < n; ++i) {
    ll x; cin >> x;
    sum += x;
    maxx = max(maxx, sum);
    if (sum - maxx < delta) delta = sum - maxx, ans = maxx;
  }
  return cout << ans << '\n', void();
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}