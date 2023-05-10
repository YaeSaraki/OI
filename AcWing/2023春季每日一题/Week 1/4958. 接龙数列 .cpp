#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

const int kN = 1e5 + 1;

int n;
int g[10];
int ans = 0;

inline void solve() {
  cin >> n;
  string tempstr;
  for (int i = 1; i <= n; ++i) {
    cin >> tempstr;
    int l = tempstr[0] - '0', r = tempstr[tempstr.length() - 1] - '0';
    int temp = max(1, g[l] + 1);
    g[r] = max(g[r], temp);
    ans = max(ans, temp);
  }
  cout << n - ans << endl;
  return ;
}

bool rt = false;
int main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}