
/**
 * \link: https://ac.nowcoder.com/acm/problem/14666
 * \category: stack 
 *
 * \date: Tue Jul 11 13:52:06 CST 2023
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int rod = 0;

/** using monotonic stack.*/
inline void solve() {
  stack<int> stk;
  int n; cin >> n;
  vector<int> h(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> h.at(i);
  }
  
  /** front traversal. */
  vector<int> pre(n + 2);
  for (int i = 1; i <= n; ++i) {
    pre.at(i) = pre.at(i - 1);
    while (!stk.empty() && h.at(i) >= h.at(stk.top())) {
      ++pre.at(i);
      stk.pop();
    }
    if (!stk.empty()) ++pre.at(i);
    stk.push(i);
  }
  
  while (!stk.empty()) stk.pop();
  /** back traversal. */
  vector<int> back(n + 2);
  for (int i = n; i; --i) {
    back.at(i) = back.at(i + 1);
    while (!stk.empty() && h.at(i) >= h.at(stk.top())) {
      ++back.at(i);
      stk.pop();
    }
    if (!stk.empty()) ++back.at(i);
    stk.push(i);
  }
  
  int ans = 0, ans_id = 0;
  for (int i = 1; i <= n; ++i) {
    int num = pre.at(n) - (pre.at(i) + back.at(i + 1));
    if (ans < num) {
      ans = num;
      ans_id = i;
    }
  }
  
  cout << "Case #" << ++rod << ": " << ans_id + 1 << " " << ans << "\n";
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("/Users/Shared/test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}

