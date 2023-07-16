/**
 * @problem: NC15137 文化节
 * @link: https://ac.nowcoder.com/acm/problem/15137
 * @category: monotonic stack
 * @date: Sun Jul 16 10:25:08 CST 2023
 * @author: YaeSaraki
 **/
#pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
inline void solve() {
  int ng, n; cin >> ng >> n;
  vector<int> poems(n + 1);
  /** generator. */
  int index = 0;
  while (ng--) {
    int ns, s, a, b, mod;
    cin >> ns >> s >> a >> b >> mod;
    poems.at(++index) = s;
    while (--ns) {
      ++index;
      poems.at(index) = ((ll)poems.at(index - 1) * a + b) % mod;
      if (poems.at(index) == 0) poems.at(index) = mod;
    }
  }

  /** find the max length. */
  int max_length_index = 1;
  for (int i = 1; i <= n; ++i) if (poems.at(i) > poems.at(max_length_index))
    max_length_index = i; 

  /** clockwise traversal. */
  stack<int> stk;
  stk.push(max_length_index);
  vector<int> r(n + 1);
  for (int i = max_length_index + 1; ; ++i) {
    if (i > n) i -= n;
    if (i == max_length_index) break;
    while (stk.size() && poems.at(stk.top()) <= poems.at(i)) stk.pop();
    if (poems.at(i) != poems.at(max_length_index)) r.at(i) = stk.top();
    stk.push(i); 
  }

  while (stk.size()) stk.pop();
  /** anticlockwise traversal. */
  stk.push(max_length_index);
  vector<int> l(n + 1);
  for (int i = max_length_index - 1; ; --i) {
    if (i < 1) i += n;
    if (i == max_length_index) break;
    while (stk.size() && poems.at(stk.top()) <= poems.at(i)) stk.pop();
    if (poems.at(i) != poems.at(max_length_index)) l.at(i) = stk.top();
    stk.push(i);
  }

  ll ans = (ll)poems.at(max_length_index) * n;
  // DBG(ans);
  for (int i = 1; i <= n; ++i) {
    if (poems.at(i) == poems.at(max_length_index)) continue;
    int a, b;
    
    if (r.at(i) < i) b = i - r.at(i);
    else b = n + i - r.at(i);
    
    if (l.at(i) > i) a = l.at(i) - i;
    else  a = n + l.at(i) - i;

    ans = min(ans, (ll)(a + b - 1) * poems.at(i) + (ll)(n - a - b + 1) * poems.at(max_length_index));
  }
  cout << ans << '\n';
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
