/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
inline void solve() {
  int n; cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    int l = max(1, i - x);
    a[l] += 1;
    a[i] -= 1;
    int r = min(n, i + x);
    a[i + 1] += 1;
    a[r + 1] -= 1;
  }
  ll ans = 0, sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum += a[i];
    if (sum > 0) ++ans;
  }
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
