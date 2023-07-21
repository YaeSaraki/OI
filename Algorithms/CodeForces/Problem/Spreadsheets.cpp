/**
 * @problem: Spreadsheets
 * @link: https://www.luogu.com.cn/problem/CF1B
 * @category: string instruction
 * @date: Tue Jul 18 22:40:08 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>

using namespace std;

inline void solve() {
  string str; cin >> str;
  if (str[0] == 'R' && isdigit(str[1]) && str.find('C') != string::npos) {
    size_t p = str.find('C');
    int r = stoi(str.substr(1, p - 1));
//    cout << index << " ";
    int c = stoi(str.substr(p + 1));
//    cout << c << " ";
    string ans;
    while (c) {
      int t = (c % 26 + 25) % 26;
      ans.insert(ans.begin(), char(t + 'A'));
      c -= t;
      c /= 26;
    }
    cout << ans << r << '\n';
  } else {
    int c = 0;
    int index = 0;
    while (isalpha(str[index])) c = c * 26 + str[index++] + 1 - 'A';
    int r = stoi(str.substr(index));
    cout << "R" << r << "C" << c << "\n";
  }
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
