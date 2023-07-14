/**
 * \link: https://ac.nowcoder.com/acm/contest/61132/F
 * \category: 并查集
 *
 * \date:
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> f;

/** using 并查集. */
inline void solve2() {
  int n; cin >> n;
  /** init. */
  vector<int> a(n + 1);
  f = a;
  iota(f.begin(), f.end(), 0);
  
  for (int i = 1; i <= n; ++i) {
    cin >> a.at(i);
    f.at(a.at(i)) = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a.at(i) != i) {
      int t = f.at(i);
      swap(a.at(i), a.at(t));
      f.at(a.at(t)) = t;
      ++ans;
    }
  }
  cout << ans << '\n'; 
}


/** compressed version. */
inline void solve() {
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a.at(i);
    b.at(a.at(i)) = i;
  }
  int energy = 0;
  for (int i = 1; i <= n; ++i) {
    while (a.at(i) != i) {
      swap(a.at(i), a.at(a.at(i)));
      ++energy;
    }
  }
  cout << energy << '\n';
  return ;
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
