#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

inline void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int cnt = a.at(0);
  for (int i = 1 ; i < n; ++i) cnt &= a.at(i);
  if (cnt) return cout << "1\n", void();

  int ans = 0, k = 0;
  while (a.at(k) == 0 && k < n) ++k, ++ans;
  if (k == n) return cout << ans << '\n', void();

  cnt = a.at(k);
  for (int i = k + 1; i < n; ++i) {
    cnt &= a.at(i);
    // cout << cnt << " ";
    if (cnt == 0) {
      ++ans;
      if (i != n - 1) cnt = a.at(i + 1);
    }
  }
  // cout << (1 & 2) << '\n';
  cout << ans << '\n';
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}