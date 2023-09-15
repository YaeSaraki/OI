#include <iostream>
#include <algorithm>
using namespace std;

inline void solve() {
  int n; cin >> n;
  if (n == 2 || n == 4) return cout << "-1", void();
  else {
    if (n & 1) {
      int x = (n + 1) / 2;
      cout << x << endl;
      for (int i = 1; i <= x; ++i) cout << i << " ";
    } else {
      int x = n / 2;
      cout << x << endl;
      cout << "0" << " ";
      for (int i = 2; i <= x; ++i) cout << i << " "; 
    }
  }
  return ;
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}