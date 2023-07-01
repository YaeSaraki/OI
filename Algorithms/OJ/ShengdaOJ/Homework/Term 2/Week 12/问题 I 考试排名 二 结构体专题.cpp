#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct ACM_Member {
  string name;
  int solved = 0, time = 0;
  bool operator <(const ACM_Member &A) const {
    if (solved != A.solved) return solved > A.solved;
    if (time != A.time) return time < A.time;
    if (name != A.name) return name < A.name;
    return false;
  }
} acmer[101];

void inline solve() {
  int m; cin >> m;
  int i = 0, tempint;
  string name; while (cin >> acmer[i].name) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &tempint);
      if (tempint > 0) ++acmer[i].solved, acmer[i].time += tempint;
      char ch = getchar();
      if (ch == '(') {
        scanf("%d", &tempint);
        acmer[i].time += (tempint) * 20;
        getchar();
      }
    }
    ++i;
  }
  sort(acmer, acmer + i);
  for (int j = 0; j < i; ++j) printf("%-10s %2d %4d\n", acmer[j].name.data(), acmer[j].solved, acmer[j].time);
  return ;
}

bool rt = false;
signed main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}