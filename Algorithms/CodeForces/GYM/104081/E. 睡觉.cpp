#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


inline void solve() {
  int x, t, k, n, d; cin >> x >> t >> k >> n >> d;
  vector<int> a(2 * n + 1);
  int temp;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) { cin >> temp; a[i] = temp > d ? 1 : -1; cnt += a[i]; a[n + i] = a[i]; }
  if (cnt < 0) return cout << "YES" << '\n', void();

  int time = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    x += a[i];
    if (x <= k) ++time;
    else time = 0;
    if (time == t || time == n) return cout << "YES" << '\n', void();
  }
  return cout << "NO" << '\n', void();
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}