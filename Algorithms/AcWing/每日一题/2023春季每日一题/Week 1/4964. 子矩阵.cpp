/**
 * https://www.acwing.com/problem/content/4967/
 * 单调队列
 * 
 * 
 * Author： (_Dijkstra)[https://www.acwing.com/solution/content/184247/]
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;
const int MOD = 998244353;
const int kN = 1001;
int a[kN][kN], minn[kN][kN], maxx[kN][kN], minn2[kN][kN], maxx2[kN][kN];

inline void solve() {
  int n, m, aa, bb; cin >> n >> m >> aa >> bb;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

  for (int i = 0; i < n; ++i) {
    multiset<int> ms;
    for (int j = 0; j < bb; ++j) ms.insert(a[i][j]);
    auto it = ms.end(); --it;
    maxx[i][bb - 1] = *it;
    minn[i][bb - 1] = *ms.begin();
    for (int j = bb; j < m; ++j) {
      ms.insert(a[i][j]);
      ms.erase(ms.find(a[i][j - bb]));
      auto it = ms.end(); --it;
      maxx[i][j] = *it;
      minn[i][j] = *ms.begin();
    }
  }
  // todo min
  for (int i = bb; i < m; ++i) {
    multiset<int> ms;
    for (int j = 0; j < aa; ++j) ms.insert(minn[j][i]);
    minn2[aa - 1][i] = *ms.begin();
    for (int j = aa; j < n; ++j) {
      ms.insert(minn[j][i]);
      ms.erase(ms.find(minn[j - aa][i]));
      minn2[j][i] = *ms.begin();
    }
  }
  // todo max
  for (int i = bb; i < m; ++i) {
    multiset<int> ms;
    for (int j = 0; j < aa; ++j) ms.insert(maxx[j][i]);
    auto it = ms.end(); --it;
    maxx2[aa - 1][i] = *it;
    for (int j = aa; j < n; ++j) {
      ms.insert(maxx[j][i]);
      ms.erase(ms.find(maxx[j - aa][i]));
      auto it = ms.end(); --it;
      maxx2[j][i] = *it;
    }
  }

  long long ans(0);
  for (int i = aa - 1; i < n; ++i)
    for (int j = bb - 1; j < m; ++j) { ans += (minn[i][j] * 1LL % MOD) * (maxx[i][j] * 1LL % MOD); ans %= MOD; }
  cout << ans << "\n";
  return ;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}
