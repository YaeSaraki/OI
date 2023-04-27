#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

bool rt = false;

inline void solve() {
  int M, S, T; cin >> M >> S >> T;
  int t = 0, m = M, s1 = 0, s2 = 0, flag = 0;
  while (t < T) {
    s1 += 17, t += 1;
    if (m >= 10) { m -= 10; s2 += 60; }
    else m += 4;
    if (s1 < s2) s1 = s2;
    if (s1 > S) { flag = 1; break; }
  }
  if (!flag) return cout << "No" << endl << s1 << endl, void();
  else return cout << "Yes" << endl << t << endl, void();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0; 
}