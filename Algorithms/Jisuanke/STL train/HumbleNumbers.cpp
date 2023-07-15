/**
 * @problem: [USACO3.1] 丑数 Humble Numbers
 * @link: https://www.jisuanke.com/problem/T3473 & https://www.luogu.com.cn/problem/P2723
 * @category: STL priority_queue set
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
#include <climits>

#define int long long
using namespace std;
using ll = long long;

inline void solve() {
  int k, n; cin >> k >> n;
  vector<int> factors(k);
  for (auto &it : factors) cin >> it;
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 1;
  vector<int> ptr(k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j)
      dp[i] = min(dp[i], dp[ptr[j]] * factors[j]);
    for (int j = 0; j < k; ++j)
      while (dp[i] >= dp[ptr[j]] * factors[j]) { ++ptr[j]; }
  }
//  for (auto it : dp) cout << it << " ";
  cout << dp[n];
}

/** using hash + heap 91(100)point. n*/
inline void solve2() {
  int k, n; cin >> k >> n;
  vector<int> factors(k);
  for (auto &it : factors) cin >> it;
  priority_queue<int, vector<int>, greater<> > heap;
  set<int> hashSet;
  heap.emplace(1);
  hashSet.emplace(1);
  int humble_number = 0;
  for (int i = 0; i <= n; ++i) {
    int now = heap.top(); heap.pop();
    humble_number = now;
    for (auto factor: factors) {
      int next = now * factor;
      if (!hashSet.count(next)) {
        hashSet.emplace(next);
        heap.emplace(next);
      }
    }
  }
  cout << humble_number << '\n';
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
