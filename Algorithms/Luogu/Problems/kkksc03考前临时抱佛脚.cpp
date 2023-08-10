/**
 * @problem: P2392 kkksc03考前临时抱佛脚
 * @link: https://www.luogu.com.cn/problem/P2392
 * @category: 搜索 递归
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <climits>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;


constexpr int kN = 23;
int minn;
int left, right;
int timetable[4][kN];
int problem_number[4];

/** using DFS 暴力枚举. */
void DFS(int u, int w) {/** u represent the current problem, w represent the current subject index. */
  if (u == problem_number[w]) {
    minn = std::min(minn, std::max(left, right));
    return;
  }

  left += timetable[w][u];
  DFS(u + 1, w);
  left -= timetable[w][u];

  right += timetable[w][u];
  DFS(u + 1, w);
  right -= timetable[w][u];

}


inline void solve() {
  for (int i = 0; i < 4; ++i) std::cin >> problem_number[i];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < problem_number[i]; ++j) std::cin >> timetable[i][j];
  }
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    left = right = 0;
    minn = INT_MAX;
    DFS(0, i);
    ans += minn;
  }
  std::cout << ans << '\n';
}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
