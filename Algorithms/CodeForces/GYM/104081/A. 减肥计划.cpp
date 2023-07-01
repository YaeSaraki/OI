#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int kN = 1e6 + 2333333;
int a[kN];

inline void solve() {
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int maxx = a[0], maxx_i = 0, time = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > maxx) {
      time = 1;
      maxx_i = i;
      maxx = a[i];
    } else ++time;
    if (time == k) break;
  }
  return cout << maxx_i + 1 << '\n', void();
}

bool rt = false;
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}