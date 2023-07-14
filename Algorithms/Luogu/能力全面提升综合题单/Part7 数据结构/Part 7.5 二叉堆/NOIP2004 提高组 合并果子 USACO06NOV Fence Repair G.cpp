/**
 * \link: https://www.luogu.com.cn/problem/P1090
 * \category: greedy heap priority_queue
 *
 * \date:
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const bool kMergeTheFruit = true;
inline void solve() {
  int n; cin >> n;
  priority_queue<int, vector<int>, greater<int> > binaryHeap;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    binaryHeap.push(x);
  }

  /** merge the fruit and caculate the ans. */
  int ans = 0;
  while (kMergeTheFruit) {
    if (binaryHeap.size() == 1) break; 
    int fruit1 = binaryHeap.top();
    binaryHeap.pop();
    int fruit2 = binaryHeap.top();
    binaryHeap.pop();
    int merged_fruit = fruit1 + fruit2;
    ans += merged_fruit;
    binaryHeap.push(merged_fruit);
  }
  cout << ans << '\n';
  return;
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
