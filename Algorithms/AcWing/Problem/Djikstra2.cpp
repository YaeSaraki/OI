#include <algorithm>
#include <iostream>
#include <queue>
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
auto heap = std::priority_queue<PI, std::vector<PI>, std::greater<> >();

auto dis = std::array<int, kN>();
auto vis = std::array<int, kN>();


inline void solve() {
  dis.fill(MAX);
  
  int n, m; std::cin >> n >> m;
  while(m--) {
    int x, y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
  }

  dis[1] = 0;
  heap.emplace(0, 1);
  while (!heap.empty()) {
    auto [d, x] = heap.top(); heap.pop();
    if (vis[x]) continue;
    vis[x] = true;
    for (auto [y, v] : edge[x]) {
      if (dis[y] > dis[x] + v) {
        dis[y] = dis[x] + v;
        heap.emplace(dis[y], y);
      }
    }
  }

  std::cout << dis[n] << "\n";
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

