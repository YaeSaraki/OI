#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#define endl '\n'

using namespace std;
using ll = long long;

inline void solve() {
  int n; cin >> n;
  int maxx = sqrt(n);
  for (int len = 12; len >= 1; --len) {
    for (int start = 2; start <= maxx; ++start) {
      ll sum = 1;
      for (int i = start; i - start <= len - 1; ++i) sum *= i;
      if (n % sum == 0) {
        cout << len << endl << start;
        for (int j = start + 1; j - start <= len - 1; ++j) cout << "*" << j;
        return ;
      }
    }
  }
  return cout << "1" << endl << n, void();
}


int tc = false;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (tc) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}