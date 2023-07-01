#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

// #define ONLINE_JUDGE
const int kN = 101;

int n, m;
int maxstep;
char a[kN][kN];
int x_start, y_start = 2, ans;
int dir[5][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};

void dbg(string str) { cout<< str; }

void DFS(int y, int x, int point, int step) {
  if (x > m || y > n || x < 1 || y < 1) return ;
  if (step > 50) return ;
  if (a[y][x] == '#') return ;
  if (point && x == x_start && y == y_start) return ans = max(ans, point), void();
  double f = 1;
  for (int i = 0; i <= 5; ++i) {
    int yy = y + dir[i][0], xx = x + dir[i][1];
    if (a[yy][xx] == '@' || (x == xx && y == yy && f)) {
      bool flag = a[yy][xx] == '@';
      if (flag) ++point, a[yy][xx] = '.', f = 0;

      if (a[y][x] == '.') {
        DFS(y + 1, x, point, step + 1), DFS(y - 1, x, point, step + 1), DFS(y, x + 1, point, step + 1), DFS(y, x - 1, point, step + 1);
      } else if (a[y][x] == 'X') {
        a[y][x] = '#';
        DFS(y + 1, x, point, step + 1), DFS(y - 1, x, point, step + 1), DFS(y, x + 1, point, step + 1), DFS(y, x - 1, point, step + 1);
        a[y + 1][x] = 'X';
      }

      if (flag) a[yy][xx] = '@';
    }
  }
  return ;
}

inline void solve() {
  while (scanf("%d%d", &n, &m) == 2) {
    maxstep = (n - 1) * (m - 1);
  //  dbg("start");
    // todo input
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) 
        cin >> a[i][j];
  //  dbg("input!");
    // todo init
    ans = 0;
    for (int i = 1; i <= max(m, n); ++i) {
  // cout << x_start << " " << y_start << '\n';
    // dbg("loop\n");
      if (i <= m) {
        if (a[1][i] == '.') { x_start = i, y_start = 1; break; }
        if (a[n][i] == '.') { x_start = i, y_start = n; break; }
      }
      if (i <= n) {
        if (a[i][1] == '.') { x_start = 1, y_start = i; break; }
        if (a[i][m] == '.') { x_start = m, y_start = i; break; }
      }
    }
  // dbg("wow!\n");
  // cout << m << " " << n << '\n';
  // cout << x_start << " " << y_start << '\n';
  // cout << a[y_start][x_start];

    DFS(y_start, x_start, 0, 0);
    cout << ans << '\n';
  }
  return ;
} 

bool rt = false;
signed main() {
  // ios::sync_with_stdio(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}