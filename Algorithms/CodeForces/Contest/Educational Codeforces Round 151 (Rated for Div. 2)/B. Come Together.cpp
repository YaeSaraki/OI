/**
 * \link: https://codeforces.com/contest/1845/problem/B
 * \category:  geometry implementation math
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void inline solve() {
  int x1, y1; cin >> x1 >> y1;
  int x2, y2; cin >> x2 >> y2;
  int x3, y3; cin >> x3 >> y3;
  pair<int, int> vector1 = {x2 - x1, y2 - y1};
  pair<int, int> vector2 = {x3 - x1, y3 - y1};
  int ans = 1;
  if (vector1.first < 0 && vector2.first < 0) ans += -max(vector1.first, vector2.first);
  if (vector1.first > 0 && vector2.first > 0) ans += min(vector1.first, vector2.first);
  if (vector1.second < 0 && vector2.second < 0) ans += -max(vector1.second, vector2.second); 
  if (vector1.second > 0 && vector2.second > 0) ans += min(vector1.second, vector2.second); 
  cout << ans << '\n';
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}