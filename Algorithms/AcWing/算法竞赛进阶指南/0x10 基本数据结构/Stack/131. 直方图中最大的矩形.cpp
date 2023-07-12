/**
  * \link: https://www.acwing.com/problem/content/133/
  * \category: 单调栈 
  * 
  *
  * \note: 
  **/
#include <algorithm>
#include <array>
#include <iostream>
#include <stack>

// #define ONLINE_JUDGE 
using namespace std;
using ll = long long;

const int kN = 1e5 + 233;

array<int, kN> h, l, r;
stack<int> stk;

inline void solve() {
  int n; while (cin >> n , n) {
    for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
    /** define the bound  */
    h[0] = h[n + 1] = -1;
    stk.push(0);
    
    /** 用单调栈找当前位置的左边界线 */
    for (int i = 1; i <= n; ++i) {
      while (h[i] <= h[stk.top()]) stk.pop();
      l[i] = stk.top();
      stk.push(i);
    }

    /** define the bound to next */
    while (!stk.empty()) stk.pop();
    stk.push(n + 1);
    
    /** 用单调栈找当前位置的右边界线 */
    for (int i = n; i; --i) {
      while (h[i] <= h[stk.top()]) stk.pop();
      r[i] = stk.top();
      stk.push(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans,(ll) (r[i] - l[i] - 1) * h[i]);
    cout << ans << '\n';
  }
  return ;
}

bool rt = false;
 int main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
 }