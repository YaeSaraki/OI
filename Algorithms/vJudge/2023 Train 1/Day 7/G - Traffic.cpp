/**
 * \link: https://vjudge.csgrandeur.cn/problem/HDU-6573
 * \category: 暴力 
 * 
 * 
 * 
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int nb, dx;
  int a;
  while (~scanf("%d%d", &dx, &nb)) {
    int book[2010] = {0}, b[1010];
    for (int i = 0; i < dx; i++) {
      scanf("%d", &a);
      book[a] = 1;
    }
    for (int i = 0; i < nb; i++) {
      scanf("%d", &b[i]);
    }
    int f = 0;
    for (int i = 0; i <= 1000; i++) {
      int t = 0;
      if (f == 1) continue;
      for (int j = 0; j < nb; j++) {
        int d = b[j] + i;
        if (book[d] == 0) t++;
        if (t == nb) {
          printf("%d\n", i);
          f = 1;
          break;
        }
      }
    }
  }
}

// signed main() {
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   #ifndef ONLINE_JUDGE
//   freopen("test.in", "r", stdin);
//   #endif
//   if(rt) { int T; cin >> T; while(T--) solve(); }
//   else solve();
//   return 0;
// }