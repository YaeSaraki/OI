#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

inline void solve() {
  int n, k; cin >> n >> k;
  int ans = n;
  string s[n];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    if (s[i] != s[0]) --ans;
  }
  cout << ans << '\n';
}

bool rt = true;
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) {int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}