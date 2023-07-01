/**
 * \link: https://codeforces.com/contest/1833/problem/A
 * \category: implementation strings *800
 * 
 * 
 * 
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

inline void solve() {
  int n; cin >> n;
  map<string, int> m;
  string str; cin >> str;
  for (int i = 0; i < n - 1; ++i) {
    string temp = str.substr(i, 2);
    if (!m.count(temp)) ++m[temp];
  }
  cout << m.size() << '\n';
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}