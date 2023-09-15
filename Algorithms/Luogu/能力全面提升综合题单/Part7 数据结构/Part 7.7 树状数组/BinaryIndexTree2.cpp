#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

inline int Lowbit(int x) { return x & -x; }

void add(int x, int k) {
  while (x <= n) {
    v[x] += k;
    x += Lowbit(x);
  }
}

int Query(int x) {
  int cnt = 0;
  while (x) {
    cnt += v[x];
    x -= Lowbit(x);
  }
  return cnt;
}

inline void solve() {
  int q;
  cin >> n >> q;
  v = vector<int>(n + 1);
  int last = 0, now = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> now;
    add(i, now - last);
    last = now;
  }
  while (q--) {
    int op; cin >> op;
    switch(op) {
      case 1 : {
        int x, y , k; cin >> x >> y >> k;
        add(x, k), add(y + 1, -k);
        break;
      }
      case 2 : {
        int x; cin >> x;
        cout << Query(x) << "\n";
        break;
      }
    }
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
