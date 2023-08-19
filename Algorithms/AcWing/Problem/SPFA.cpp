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
#include <queue>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 1e5 + 233;

int n, m;
auto edge = std::array<std::vector<PI>, kN>();

auto dis = std::array<int, kN>();
auto cnt = std::array<int, kN>();
auto vis = std::array<bool, kN>();
auto que = std::queue<int>();

inline void solve() {
  dis.fill(INT_MAX);

  std::cin >> n >> m;
  while (m--) {
    int x, y, v; std::cin >> x >> y >> v;
    edge[x].emplace_back(y, v);
  }

  dis[1] = 0, vis[1] = true;
  que.emplace(1);

  while (!que.empty()) {
    int x = que.front(); que.pop();
    vis[x] = false;
    for (auto [y, v] : edge[x]) {
      if (dis[y] > dis[x] + v) {
        dis[y] = dis[x] + v;
        cnt[y] = cnt[x] + 1;
        if (cnt[y] >= n) continue;
        if (!vis[y]) que.emplace(y), vis[y] = true;
      }
    }
  }

  if (dis[n] != INT_MAX) std::cout << dis[n] << "\n";
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

