#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

inline void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n + 1), b;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n == k) return cout << "0\n", void();
  for (int i = 0; i < n - 1; ++i) b.push_back(abs(a.at(i) - a.at(i + 1)));
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i <= b.size() - k; ++i) {
    // cout << b.at(i) << ' ';
    ans += b.at(i);
  }
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