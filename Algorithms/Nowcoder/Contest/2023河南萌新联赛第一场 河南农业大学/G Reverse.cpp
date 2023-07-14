/**
 * \link: https://ac.nowcoder.com/acm/contest/61132/G
 * \category: 暴力
 * 
 * \date:
 * \author: YaeSaraki
 **/
#pragma GCC optimize("O2")


#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using PI = pair<int, int>;

bool cmp(PI &A, PI &B) {
  int a = A.second - A.first;
  int b = B.second - B.first;
  if (a != b) return  a > b; 
  return false;
}

inline void solve() {
  int n; cin >> n;
  string str; cin >> str;
  n = str.size();
  vector<PI> v;
  for (int i = 0; i < n; ++i) {
    int l = i;
    while (i < n && str.at(i) == '1') ++i;
    if (l != i) v.push_back({l, i});
  }

  if (v.size()) {
    if (v.size() == 1) return cout << v[0].second - v[0].first << '\n', void();
    sort(v.begin(), v.end(), cmp);
    cout << v[0].second - v[0].first + v[1].second - v[1].first << '\n';
  } else {
    cout << "0\n";
  }
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
