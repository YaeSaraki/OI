/**
 * https://vjudge.csgrandeur.cn/problem/CSG-1157
 * \category: 
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Team {
  int score = 0, js = 0, sum = 0;
} t[128];

inline void solve() {
  memset(t, 0, sizeof t);
  char t1, t2;
  for (int i = 1; i <= 15; ++i) {
    int tt1[2], tt2[2];
    cin >> t1 >> t2  >> tt1[0] >> tt2[0] >> tt1[1] >> tt2[1];
    for (int i = 0; i < 2; ++i) {
      if (tt1[i] > tt2[i]) {
        t[t1].score += 3;
        t[t1].js += tt1[i] - tt2[i];
        t[t2].js -= tt1[i] - tt2[i];
        t[t1].sum += tt1[i];
        t[t2].sum += tt2[i];
      } else if (tt1[i] < tt2[i]) {
        t[t2].score += 3;
        t[t2].js += tt2[i] - tt1[i];
        t[t1].js -= tt2[i] - tt1[i];
        t[t2].sum += tt2[i];
        t[t1].sum += tt1[i];
      } else {
        t[t1].score += 1, t[t2].score += 1;
        t[t1].sum += tt1[i], t[t2].sum += tt2[i];
      }
    }
  }
  for (int i = 'A'; i <= 'F'; ++i) {
    cout << t[i].score << " " << t[i].js << " " << t[i].sum << '\n';
  }
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}