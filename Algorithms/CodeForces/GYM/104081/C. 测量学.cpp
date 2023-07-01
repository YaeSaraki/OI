#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const double PI = acos(-1);

inline void solve() {
  int n;
  double r, theta;
  cin >> n >> r >> theta;
  theta = min(theta, 2 * PI - theta);
  double ans = r * theta;
  for (int i = 1; i <= n; ++i) {
    double r1; cin >> r1;
    ans = min(ans, 2 * (r - r1) + r1 * theta);
  }
  printf("%.6lf\n", ans);
  return ;
}

bool rt = false;
signed main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}
