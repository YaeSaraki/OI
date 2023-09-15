#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
using ll = long long;

struct student {
  ll num;
  string name;
  int score1, score2, score3, allscore;
  void CulAllscore() { allscore = score1 + score2 + score3; }
  bool operator <(const student &A) const {
    if (allscore != A.allscore) return allscore > A.allscore;
    if (name != A.name) return name < A.name;
    return false; 
  }
} stu[233];



void inline solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> stu[i].num >> stu[i].name >> stu[i].score1 >> stu[i].score2 >>
        stu[i].score3;
    stu[i].CulAllscore();
  }
  sort(stu, stu + n);
  for (int i = 0; i < n; ++i)
    cout << stu[i].num << " " << stu[i].name << " " << stu[i].score1 << " "
         << stu[i].score2 << " " << stu[i].score3 << " " << stu[i].allscore
         << '\n';
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