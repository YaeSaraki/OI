/**
 * \link: https://codeforces.com/contest/1832/problem/A
 * \category: 字符串 回文
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void inline solve() {
  string str; cin >> str;
  if (str == string(str.rbegin(), str.rend())) {
    map<char, int> m;
    for (auto it : str) ++m[it];
    if (m.size() > 2) return cout << "YES" << '\n', void();
    if (str.size() > 3 && m.size() == 2) {
      int time = 0;
      for (auto it : m)
        if (it.second > 1) ++time;
      if (time > 1) return cout << "YES" << '\n', void(); 
    }
  }
  return cout << "NO" << '\n', void();
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