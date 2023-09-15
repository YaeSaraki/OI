/**
 * \link: https://www.luogu.com.cn/problem/P1886
 * \category: 滑动窗口 单调队列 mutiset
 * \author: https://www.luogu.com.cn/blog/Mush-room-Liu/solution-p1886
 * 
 * 
*/
#pragma G++ optimize(3)
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
using ll = long long;

const int kN = 1001001;
int a[kN], ans_max[kN];

int inline read() {
  int x = 0, k = 1; char c; cin >> c;
  while ('0' > c || c > '9') { if (c == '-') k = -1, c = getchar(); }
  while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * k;
}

void inline solve() {
  int n, m; n = read(), m = read();
  multiset<int> ms;
// cout << "hello" << '\n';
  for (int i = 0; i < n; ++i) a[i] = read(); 
  for (int i = 0; i < m; ++i) ms.insert(a[i]);
  cout << *ms.begin() << " ";
  int j = 0;
  auto it = ms.end();
  --it;
// cout << *it << endl;
  ans_max[j++] = *it;
  for (int i = m; i < n; ++i) {
    ms.insert(a[i]);
    ms.erase(ms.find(a[i - m]));
    cout << *ms.begin() << " ";
    it = ms.end();
    --it;
  // cout << *it << endl;
    ans_max[j++] = *it;
  }
  cout << '\n';
  for (int i = 0; i < j; ++i) cout << ans_max[i] << " ";
  return cout << '\n', void();
}

bool rt = false;
signed main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}