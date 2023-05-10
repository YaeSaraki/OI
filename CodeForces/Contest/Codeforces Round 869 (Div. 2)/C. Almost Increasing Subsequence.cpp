#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 2; i <= n - 1; ++i) {
    if (a[i - 1] >= a[i] && a[i] >= a[i + 1]) s[i] = s[i - 1] + 1;
    else s[i] = s[i - 1];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    int len = r - l + 1;
    if (len <= 2) cout << len << '\n';
    else cout << len - (s[r - 1] - s[l]) << '\n';
  }
  return ;
}

bool rt = false;
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) {int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}