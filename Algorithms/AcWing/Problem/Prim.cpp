#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <array>
#include <queue>
#include <set>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 1e4 + 233;

auto edge = std::array<std::vector<PI>, 2 * kN>();
auto heap = std::priority_queue<PI, std::vector<PI>, std::greater<> >();
auto vis = std::set<int>();
auto dis = std::array<int, kN>();

inline void solve() {
  dis.fill(INT_MAX);

  int n, m; std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
    edge[y].emplace_back(x, v);
  }

  int ans = 0, cnt = 0;
  dis[1] = 0;
  
  heap.emplace(0, 1);
  int times = n;
  while (!heap.empty() && vis.size() < n) {
    auto [d, x] = heap.top(); heap.pop();
    /* 将元素加入到排列好的集合中，如果元素已经在排列好的集合中就跳过. */
    if (vis.count(x)) continue;
    vis.emplace(x) ;

    /* 加上最小边d. */
    ans += d;

    /* 遍历该点, 堆定即为边权最小的边.*/
    for (auto [y, v] : edge[x])
      if (!vis.count(y)) heap.emplace(v, y);
  }
  std::cout << (vis.size() != n ? "orz\n" : std::to_string(ans));
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

