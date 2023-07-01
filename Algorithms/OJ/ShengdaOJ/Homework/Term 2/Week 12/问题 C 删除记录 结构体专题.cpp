
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
using ll = long long;

struct student {
  string name;
  int score1, score2, score3;
} stu;

map<ll, student> mStu;

void inline solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    ll num; cin >> num >> stu.name >> stu.score1 >> stu.score2 >> stu.score3;
    mStu[num] = stu;
  }

  ll num; cin >> num;
  if (mStu.count(num)) mStu.erase(num);
  else return cout << "error!" << '\n', void();

  for (auto it : mStu)
    cout << it.first << " " << it.second.name << " " << it.second.score1 << " "
         << it.second.score2 << " " << it.second.score3 << '\n';
  return ;
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