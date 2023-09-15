/**
 * @problem: 96. 奇怪的汉诺塔
 * @link: https://www.acwing.com/problem/content/98/
 * @category: 递归
 * @date: Jul 17 15:58:25 CST 2023
 * @author: YaeSaraki
 **/
#pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

inline void solve() {
  int n = 12;
  vector<int> three(n + 1), four(n + 1, 0x3F3F3F3F);
  /** get the three tower. */
  for (int i = 1;  i <= n; ++i) {
    three.at(i) = 1 + three.at(i - 1) * 2;
  }
  
  /** get the four tower. */
  four.at(1) = 1;
  for (int i = 1;  i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      four.at(i) = min(four.at(i), four.at(j) * 2 + three.at(i - j));
    }
  }

  for (int i = 1;  i <= n; ++i) cout << four.at(i) << "\n";
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
