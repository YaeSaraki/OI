#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100;

struct Node {
  int t, d, l;
} P[N];

int n;
int st[N];

bool DFS(int step, int last) {
  if (step == n) return true;
  for (int i = 0; i < n; ++i) {
    int t = P[i].t, d = P[i].d, l = P[i].l;
    if (!st[i] && last <= d + l)  {
      st[i] = true;
      if (DFS(step + 1, max(last, t) + l)) return true;
      st[i] = false;
    }
  }
}

inline void solve() {
  memset(st, 0, sizeof st);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> P[i].t >> P[i].d >> P[i].l;
  if (DFS(0, 0)) puts("YES");
  else puts("NO");
}

bool rt = true;
int main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}