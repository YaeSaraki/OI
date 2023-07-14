/**
 * \link: https://ac.nowcoder.com/acm/contest/61132/E
 * \category: 暴力枚举 前缀和 二分
 *
 * \date:
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;

/** using 前缀和 & 二分. */
inline void solve2() {
  int n, m; cin >> n >> m;
  vector<ll> a(n + 1), presum(n + 1); // ! 注意presum数组要开 long long
  unordered_set<ll> s; // ! set集合同样要开longlong
  for (int i = 1; i <= n; ++i) {
    cin >> a.at(i);
    presum.at(i) = presum.at(i - 1) + a.at(i);
    s.insert(presum.at(i)); 
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (s.count(presum.at(i - 1) + m)) ++ans;
  }
  cout << ans << '\n';
}

/** using 暴力枚举. */
inline void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a.at(i);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = a.at(i);
    if (cnt == m) ++ans;
    for (int j = i + 1; j < n; ++j) {
      cnt += a.at(j);
      if (cnt == m) ++ans;
      if (cnt > m) break;
    }
  }
  cout << ans << '\n';
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
