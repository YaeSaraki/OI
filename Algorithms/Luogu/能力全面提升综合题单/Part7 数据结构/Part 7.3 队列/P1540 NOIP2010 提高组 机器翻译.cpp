/**
 * \link: https://www.luogu.com.cn/problem/P1540 
 * \category: queue impliment
 * 
 * \date: Tue Jul 11 08:54:51 CST 2023 
 * 
 **/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


inline void solve() {
  int n, k; cin >> k >> n;
  int ans = 0;
  vector<int> que;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    /** query. */
    if (find(que.begin(), que.end(), x) == que.end()) {
      que.push_back(x);
      ++ans;
    } 

    /** if the memory is full, earse the back words. */
    while (que.size() > k) que.erase(que.begin());
  }
  cout << ans << '\n';
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