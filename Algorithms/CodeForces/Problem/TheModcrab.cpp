/**
 * @problem: Educational Codeforces Round 34 (Rated for Div. 2) B. The Modcrab
 * @link: https://codeforces.com/problemset/problem/903/B
 * @category: greedy implementation *1200
 * @date: Wed Jul 19 21:17:27 CST 2023
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
  int h1, a1, c1; cin >> h1 >> a1 >> c1;
  int h2, a2; cin >> h2 >> a2;
  vector<bool> ans;
  while (h2 > 0) {
    if (h1 > a2 || a1 >= h2) {
      h2 -= a1;
      ans.push_back(true);
    } else {
      h1 += c1;
      ans.push_back(false);
    }
    h1 -= a2;
  }
  cout << ans.size() << '\n';
  for (auto it : ans) cout << (it ? "STRIKE\n" : "HEAL\n");
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
