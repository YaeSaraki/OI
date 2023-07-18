/**
 * @problem: P1168 中位数
 * @link: https://www.luogu.com.cn/problem/P1168
 * @category: binaryheap - pairingheap
 * @date: Sun Jul 16 16:50:27 CST 2023
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;


/** using pairing heap. */
inline void solve() {
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<> > minHeap;
  int n; cin >> n;
  int x; cin >> x;
  int mid = x;
  cout << mid << '\n';
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    if (x > mid) minHeap.emplace(x);
    else maxHeap.emplace(x);
    if (i & 1) {
      while (minHeap.size() != maxHeap.size()) {
        if (minHeap.size() > maxHeap.size()) {
          maxHeap.push(mid);
          mid = minHeap.top(); minHeap.pop();
        } else {
          minHeap.push(mid);
          mid = maxHeap.top(); maxHeap.pop();
        }
      }
      cout << mid << '\n';
    }
  }
}

/** using STL */
inline void solve2() {
  int n; cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    nums.insert(upper_bound(nums.begin(), nums.end(), x), x);
    if ((i + 1) & 1) cout << nums.at(i >> 1) << '\n';
  }
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
