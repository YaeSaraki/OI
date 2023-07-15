/**
 * @problem: T1526 计算并集
 * @link: https://www.jisuanke.com/problem/T1526
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

inline void solve() {
  int n, m; cin >> n >> m;
  set<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    a.emplace(x);
  }
  for (int i = 0;  i < m; ++i) {
    int x; cin >> x;
    b.emplace(x);
  }
  a.insert(b.begin(), b.end());
  for (auto it : a) cout << it << " ";
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
