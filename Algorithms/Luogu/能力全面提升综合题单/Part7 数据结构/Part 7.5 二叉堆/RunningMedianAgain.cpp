/**
 * @problem: RMID2 - Running Median Again
 * @link: https://www.luogu.com.cn/problem/SP16254
 * @category: priority queue heap pairing heap 
 * @date: Sun Jul 16 17:29:58 CST 2023
 * @author: YaeSaraki
 **/
#pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

inline void solve() {
  int x, mid, n = 0;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<> > minHeap;
  while (cin >> x) {
    switch(x) {
      case 0 : return; break;
      case -1 : {
        if (n & 1) {
          cout << minHeap.top() << '\n';
          minHeap.pop();
        } else {
          cout << maxHeap.top() << '\n';
          maxHeap.pop();
        }
        --n;
        break;
      }
      default : {
        ++n;
        if (n == 1 || x >= minHeap.top()) {
          minHeap.emplace(x);
          if (!(n & 1)) maxHeap.emplace(minHeap.top()), minHeap.pop();
        } else {
          maxHeap.emplace(x);
          if (n & 1) minHeap.emplace(maxHeap.top()), maxHeap.pop();
       }
       break;
      }
    }
  }
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
