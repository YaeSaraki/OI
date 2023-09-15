/**
 * \link: https://codeforces.com/contest/1832/problem/B
 * \category: 前缀和
 * 
 * 
 * 
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void inline solve() {
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for (auto &it : a) cin >> it;
  sort(a.begin(), a.end());
  vector<ll> b(n + 1);
  for (int i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i - 1];
  ll ans = 0;
  for (int i = 0; i <= k; ++i) ans = max(ans, b[n - (k - i)] - b[2 * i]);
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