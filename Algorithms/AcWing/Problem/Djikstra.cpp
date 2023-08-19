/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 233;
const int MAX = 0x3F3F3F3F;

auto edge = std::array<std::vector<PI>, kN>();
auto dis = std::array<int, kN>();
auto vis = std::array<bool, kN>();

inline void solve() {
  /* <!> init. */
  dis.fill(MAX);

  int n, m; std::cin >> n >> m;
  while (m--) {
    int x, y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
  }
  
  /* Start point. */
  dis[1] = 0;

  for (int i = 0; i < n; ++i) {
    /* 选出最小节点 */
    int x = 0, min_dis = MAX;
    for (int j = 1; j <= n; ++j)
      if (!vis[j] && dis[j] < min_dis) x = j, min_dis = dis[j]; 
    
    vis[x] = true;
    
    /* 遍历最小节点周围各个节点的值， 更新与原点距离. */
    for (auto [y, v] : edge[x])
      if (dis[y] > dis[x] + v) dis[y] = dis[x] + v;
  
  }
  if (dis[n] != MAX) std::cout << dis[n] << "\n"; 
  else std::cout << "-1\n";

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

