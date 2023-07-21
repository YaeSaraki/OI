/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
#define int long long

inline void solve() {
  int n, p; cin >> n >> p;
  int maxx = 0;
  int sum = 0;
  unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    sum += x;
    maxx = max(maxx, x);
    ++m[x];
  }
//     cout << sum * 2 << " " << p << " ";
  if (sum * 2 < p) return cout << "-1\n", void();
  int t = m[maxx];
  while (p > 0) {
    --maxx;
    p -= 2 * t;
    if (m.count(maxx)) t += m[maxx];
  }
  cout << maxx << '\n';
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
