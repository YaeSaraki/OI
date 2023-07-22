/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <array>

#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define ONLINE_JUDGE

using namespace std;
using ll = long long;
using PI = pair<int, int>;
#define int long long
const int kN = 1e7;
array<char, kN> str;

inline void solve() {
  int n, k; cin >> n >> k;
  for (int i = 0; i< n; ++i) cin >> str[i];
  int t = k;
  for (int i = 0; i < n && t; ++i) {
    if (str[i] == '1') continue;
    while (i < n && str[i] == '0') {
      str[i] = '1';
      ++i;
    }
    --t, --i;
  }

  if (t == 1 && k == 1) str[n - 1] = '0';
  if (n == 1 && k & 1) str[0] = '0';

  for (int i = 0 ; i < n; ++i) cout << str[i];
  cout << '\n';
}


bool rt = true;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 #ifndef ONLINE_JUDGE
   freopen("test.in", "r", stdin);
 #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
