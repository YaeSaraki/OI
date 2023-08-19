#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <climits>
#include <queue>

using PI = std::pair<int, int>;

const int kN = 501;

int n, m, k;

auto edge = std::array<std::vector<PI>, kN>();
auto vis = std::array<bool, kN>();
auto dis = std::array<int, kN>();
auto que = std::queue<int>();

auto extend() {
  auto backup = dis;
  vis.fill(0);
 
  int times = que.size();
  while (times--) {
    int x = que.front(); que.pop();
    for (auto [y, v] : edge[x]) {
      if (dis[y] > backup[x] + v) {
        dis[y] = backup[x] + v;
        if (!vis[y]) que.emplace(y), vis[y] = true;
      }
    }
  }
}

auto dijkstra() {
  dis.fill(INT_MAX);
  dis[1] = 0;
  que.emplace(1);
  for (int i = 0; i < k; ++i) extend();
}

int main() {
  std::cin >> n >> m >> k;
  while (m--) {
    int x, y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
  }
  dijkstra();
  std::cout << (dis[n] != INT_MAX ? std::to_string(dis[n]) : "impossible");
}
