/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <bitset>

using namespace std;

inline void solve() {
  int n; cin >> n;
  int q = log2(n) + 1;
  int t = n;
  while (q--) {
    int l = ceil(log2(t)) - 1;

    int i;
    for (i = l; i; --i) {
      if (i != l && (t >> i) & 1) break;
    }
    if (i == l) continue;

    int j;
//         cout << "i" << i << "  ";
    for (j = -1; j < i; ++j) {
      if (j != -1 && !((t >> j) & 1)) break;
    }
//         cout << "j" << j << "  ";
    if (j == -1) continue;

    t -= 1 << i;
    t += 1 << j;
  }
//     cout << t << " ";
  cout << n - t << '\n';
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
