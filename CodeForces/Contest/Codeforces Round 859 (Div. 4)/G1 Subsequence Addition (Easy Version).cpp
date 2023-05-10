#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

#define endl '\n'

inline void solve() {
  int n; cin >> n;
  int a[n + 1];
  ll sum = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (a[1] != 1)  return cout << "NO\n", void(); 
  sum = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] > sum) return cout << "NO\n", void();
    sum += a[i];
  }
  cout << "YES" << endl;
  return ;
}


bool tc = true;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (tc) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}