#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void solve() {
  int m, n; cin >> m >> n;
  vector<int> a(m * n);
  for (int i = 0; i < m * n; ++i) cin >> a[i]; 
  sort(a.begin(), a.end());
  int ans1 = (m * n - min(m, n))
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLIE_JUDEG
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}