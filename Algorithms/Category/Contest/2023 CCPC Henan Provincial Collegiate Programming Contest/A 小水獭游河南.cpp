#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;



inline void solve() {
  string str; cin >> str;
  set<char> s;
  if (str.size() == 1) return cout << "NaN" << endl, void();
  bool hasans = false;
  for (int i = 0; i < str.size(); ++i) {
    if (!s.count(str[i])) s.insert(str[i]);
    else break;
    string temp = str.substr(i + 1);
    string revstr = string(temp.rbegin(), temp.rend());
    if (temp == revstr) hasans = true;
  }
  if (hasans) puts("HE");
  else puts("NaN");
  return ;
}

bool rt = true;
int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}