/**
 * @problem: P1025 [NOIP2001 提高组] 数的划分
 * @link: https://www.luogu.com.cn/problem/P1025
 * @category: DFS 剪枝
 * @date: Thu Jul 20 15:22:17 CST 2023
 * @Author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
using PI = pair<int, int>;

int ans;
int num, n;

void DFS(int u, int times, int last) {
  if (u == 0 && times == n) return ++ans, void();
  if (u <= 0 || times >= n) return;
// u >= last * (n - times)
  int lim = u / (n - times);
  for (int i = last; i <= lim; ++i) {
    DFS(u - i, times + 1, i);
  }
}

inline void solve() {
  cin >> num >> n;
  ans = 0;
  DFS(num, 0, 1);
  cout << ans << '\n';
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
