/**
 * @problem: P3374 【模板】树状数组 1
 * @link: https://www.luogu.com.cn/problem/P3374
 * @category: BinaryIndexTree
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

inline int Lowbit(int x) { return x & -x; }

void Add(int x, int k) {
  while (x <= n) {
    v[x] += k;
    x += Lowbit(x);
  }
}

int Sum(int x) {
  int cnt = 0;
  while (x) {
    cnt += v[x];
    x -= Lowbit(x);
  }
  return cnt;
}

inline void solve() {
  int q; cin >> n >> q;
  v = vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    Add(i, x);
  }
  while (q--) {
    int op; cin >> op;
    switch(op) {
      case 1 : {
        int x, k; cin >> x >> k;
        Add(x, k);
        break;
      }
      case 2 : {
        int l, r; cin >> l >> r;
        cout << Sum(r) - Sum(l - 1)<< "\n";
        break;
      }
    }
  }
  return;
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
