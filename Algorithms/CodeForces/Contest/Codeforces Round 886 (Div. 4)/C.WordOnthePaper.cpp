/**
 * @problem: C. Word on the Paper
 * @link: https://codeforces.com/contest/1850/problem/C
 * @category: implementation strings
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
  int n = 8;
  vector<char> words;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch; cin >> ch;
      if (ch != '.') {
        words.push_back(ch);
      }
    }
  }
  for (int i = 0; i < words.size(); ++i) { cout << words[i]; }
  cout << '\n';
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
