/**
 * \link: https://codeforces.com/contest/1845/problem/C
 * \category: binary search dp greedy strings
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
// #define ONLINE_JUDGE
// #define int ll
using namespace std;
using ll = long long;


void inline solve() {
  string data; cin >> data;
  int n; cin >> n;
  string l, r; cin >> l >> r;
  int len = data.length();
  vector<vector<int> > pos(10);
  for (int i = 0; i < len; ++i) pos[data[i] - '0'].push_back(i);
  for (int i = 0; i < 10; ++i) pos[i].push_back(len + 1);
  int ptr = -1;
  for (int i = 0; i < n; ++i) {
    int maxx = -1;
    for (int j = l[i]; j <= r[i]; ++j) {
      int now = j - '0';
      maxx = max(maxx, *upper_bound(pos[now].begin(), pos[now].end(), ptr));
    }
    ptr = maxx;
    if (ptr >= len) return cout << "YES\n", void();
  }
  return cout << "NO\n", void();
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}