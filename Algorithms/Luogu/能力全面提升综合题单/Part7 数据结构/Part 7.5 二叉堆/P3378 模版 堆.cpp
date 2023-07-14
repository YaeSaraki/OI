/**
 * \link: https://www.luogu.com.cn/problem/P3378
 * \category: binary heap
 *
 * \date: Wed Jul 12 10:37:43 CST 2023
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline void solve() {
  priority_queue<int, vector<int>, greater<int> > binaryHeap;
  int n; cin >> n; 
  for (int i = 0; i < n; ++i) {
    int op; cin >> op;
    switch(op) {
      case 1 : {
        int x; cin >> x;
        binaryHeap.push(x);
        break;
      }
      case 2 : {
        cout << binaryHeap.top() << '\n';
        break;
      }
      case 3 : {
        binaryHeap.pop();
        break;
      }
    }
  }
  return ;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
