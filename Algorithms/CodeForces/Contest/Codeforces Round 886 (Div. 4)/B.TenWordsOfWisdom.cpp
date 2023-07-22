/**
 * @problem: B. Ten Words of Wisdom
 * @link: https://codeforces.com/contest/1850/problem/B
 * @category: implementation sortings
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
using PI = pair<int, int>;

inline void solve() {
  int n; cin >> n;
  int maxx = 0, maxx_i = 0;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    if (a > 10) continue;
    if (b > maxx) {
      maxx = b;
      maxx_i = i;
    }
  }
  cout << maxx_i + 1 << '\n';
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
