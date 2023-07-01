#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

inline void solve() {
  int m, n; cin >> m >> n;
  vector<int> a(m * n);
  for (int i = 0; i < m * n; ++i) cin >> a[i]; 
  sort(a.begin(), a.end());
  int ans1 = ((m * n - min(m, n)) * (a[m * n - 1] - a[0]) + (min(m, n) - 1) * (a[m * n - 1] - a[1]));
  int ans2 = ((m * n - min(m, n)) * (a[m * n - 1] - a[0]) + (min(m, n) - 1) * (a[m * n - 2] - a[0]));
  return cout << (ans1 > ans2 ? ans1 : ans2) << '\n', void();
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}