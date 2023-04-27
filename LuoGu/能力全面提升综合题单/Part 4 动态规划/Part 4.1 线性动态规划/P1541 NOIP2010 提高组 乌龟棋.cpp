// https://www.luogu.com.cn/problem/solution/P1541
#include <iostream>
#include <algorithm>
#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

const int kN = 41;
int f[kN][kN][kN][kN];

inline void solve() {
  int n, m; cin >> n >> m;
  int num[n + 1] = {0}, g[5] = {0};
  rep(i, 1, n) cin >> num[i];
  rep(i, 1, m) { int x; cin >> x; ++g[x]; }
  f[0][0][0][0] = num[1];
  rep(a, 0, g[1]) rep(b, 0, g[2]) rep(c, 0, g[3]) rep(d, 0, g[4]) {
    int step = 1 + a + 2 * b + 3 * c + 4 * d;
    if (a) f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + num[step]);
    if (b) f[a][b][c][d] = max(f[a][b][c][d], f[a][b - 1][c][d] + num[step]);
    if (c) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c - 1][d] + num[step]);
    if (d) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c][d - 1] + num[step]);
    // if (a || b || c || d) f[a][b][c][d] = max(f[a][b][c][d], max(f[a - 1][b][c][d], f[a][b - 1][c][d], f[a][b][c - 1][d], f[a][b][c][d - 1]) + num[step]));
  }
  cout << f[g[1]][g[2]][g[3]][g[4]] << endl;
  return ;
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}