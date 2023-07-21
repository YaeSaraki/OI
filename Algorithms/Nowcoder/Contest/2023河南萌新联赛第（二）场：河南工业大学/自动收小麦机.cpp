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
#define int long long
using namespace std;
using ll = long long;
inline void solve() {
  int n, q, k; cin >> n >> q >> k;
  vector<int> presum(n + 1);
  for (int i = 1; i <= n; ++i) {
      int x; cin >> presum[i];
      presum[i] += presum[i - 1];
  }
  vector<int> h(n + 1), preidx(n + 1), dif(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    if (h[i] == h[i - 1]) {
      dif[i] = dif[i - 1];
    } else {
      dif[i] = i - 1;
    }
    if (i - dif[i] >= k) {
      preidx[i] = i - k;
    } else {
      preidx[i] = preidx[dif[i]];
    }
  }
  while (q--) {
    int x; cin >> x;
    cout << presum[x] - presum[preidx[x]] << '\n';
  }
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
