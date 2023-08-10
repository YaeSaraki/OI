/**
 * @problem: A. Triangle
 * @link: https://codeforces.com/problemset/problem/6/A
 * @category: brute force geometry *900
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int flag = -1;
std::vector<int> sticks;
std::vector<int> material(3);

auto Triangle = []()-> void {
//  for (auto it : material) std::cout << it;
  if (material[0] + material[1] > material[2]) flag = 1;
  if (flag == 1) return;
  if (material[0] + material[1] == material[2]) flag = 0;
};

void DFS(int u, int start) {
  if (u == 3) {
    Triangle();
    return;
  }
  for (int i = start; i < sticks.size(); ++i) {
      material[u] = sticks[i];
      DFS(u + 1, i + 1);
  }
}


inline void solve() {
  int n = 4;
  sticks = std::vector<int> (n);
  for (auto &it : sticks) std::cin >> it;
  std::sort(ALL(sticks));
  DFS(0, 0);
  switch (flag) {
    case 1  : std::cout << "TRIANGLE\n"; break;
    case 0  : std::cout << "SEGMENT\n"; break;
    case -1 : std::cout << "IMPOSSIBLE\n"; break;
    default: break;
  }
}

#ifdef NORMAL_SOLVE
inline void solve() {
  std::vector<int> sticks(4);
  for (auto &it : sticks) std::cin >> it;
  std::sort(ALL(sticks));
  /* flag ->
   * -1 : represent can not construct a triangle.
   * 0  : represent can construct a bad triangle.
   * 1  : represent can construct a triangle.
   */
   int flag = -1;

  if (sticks[0] + sticks[1] > sticks[2] ||
      sticks[1] + sticks[2] > sticks[3]) flag = 1;
  else if (sticks[0] + sticks[1] == sticks[2] ||
           sticks[1] + sticks[2] == sticks[3]) flag = 0;
  switch(flag) {
    case 1  : std::cout << "TRIANGLE\n"; break;
    case 0  : std::cout << "SEGMENT\n"; break;
    case -1 : std::cout << "IMPOSSIBLE\n"; break;
    default: break;
  }
}
#endif

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
