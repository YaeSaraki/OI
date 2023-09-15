#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

struct student {
  ll num;
  string name;
  int score1, score2, score3;
} stu[101];

inline void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> stu[i].num >>  stu[i].name >> stu[i].score1 >> stu[i].score2 >> stu[i].score3;
  ll num; cin >> num;
  for (int i = 0; i < n; ++i)
    if (num == stu[i].num) {
      return cout << stu[i].num << " " << stu[i].name << " " << stu[i].score1
                  << " " << stu[i].score2 << " " << stu[i].score3 << '\n',
             void();
    }
  return cout << "Not Found" << '\n', void();
}
bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}