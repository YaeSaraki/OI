#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

// #define ONLINE_JUDGE

using namespace std;
using ll = long long;
const int kN = 10010;

int n;
int ne[kN];

struct Goods {
  int pro, dealtime;
  bool operator<(const Goods &B) {
    if (pro != B.pro) return pro > B.pro;
    if (dealtime != B.dealtime) return dealtime > B.dealtime;
    return false;
  }
} g[kN];

int find(int x) { return ne[x] == -1 ? x : ne[x] = find(ne[x]); }

void init() {
  memset(ne, -1, sizeof ne);
  for (int i = 1; i <= n; ++i) cin >> g[i].pro >> g[i].dealtime;
  sort(g + 1, g + n + 1);
  return ;
}

inline void solve() {
  init();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int t = find(g[i].dealtime);
    if (t) {
      ans += g[i].pro;
      ne[t] = t - 1;
    }
  }
  return cout << ans << '\n', void();
}

int rt = 2;
signed main () {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt == 1) { int T; cin >> T; while(T--) solve(); }
  else if (rt == 2) { while (cin >> n) solve(); }
  else solve();
  return 0;
}