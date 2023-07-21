/**
 * @problem: Watermelon
 * @link: https://www.luogu.com.cn/problem/CF4A
 * @category: brute force math *800
 * @date: Thu Jul 20 22:03:38 CST 2023
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
  int n; cin >> n;
  if (n & 1 || n == 2) cout << "NO\n";
  else cout << "YES";
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
