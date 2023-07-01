/**
 * \link: https://www.acwing.com/problem/content/1000/
 * \category: 位运算 动态规划 dp 贪心 
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
using PI = pair<string, int>;

vector<PI> V;

bool Cal(bool bit, int now) {
  for (auto it : V) {
    int t = it.second >> now & 1;
    switch(it.first[0]) {
      case 'A' : bit &= t; break;
      case 'O' : bit |= t; break;
      case 'X' : bit ^= t; break;
      default: break;
    }
  }
  return bit;
}

inline void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    PI temp; cin >> temp.first >> temp.second;
    V.push_back(temp);
  }
  int ans = 0;
  for (int i = 29; ~i; --i) {
    if (1 << i <= m) {
      bool x = Cal(0, i), y = Cal(1, i);
      if (x >= y) ans |= x << i;
      else ans |= 1 << i, m -= 1 << i;
    } else {
      ans |= Cal(0, i) << i;
    }
  }
  return cout << ans << '\n', void();
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}