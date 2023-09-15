#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define int long long
using namespace std;

using PI = std::pair<int, int>;
using i64 = __int64_t;


const int kN = 5e5 + 233;
auto edge = std::array<std::vector<int>, kN>();

void DFS(int u) {
  
  for (int x : edge[u]) {
    DFS(x);
  }
}

inline void solve() {
  int n; std::cin >> n;
  while (n--) {
    int x, y; std::cin >> x >> y;
    edge[x].emplace(y);
  }

  int ans = 0;
  for (int x : edge[1]) {
    DFS(x);
  }
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

