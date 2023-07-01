#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
using ll = long long;

struct student {
  ll num;
  string name;
  int score1, score2, score3;
} stu[101];

bool cmp1(student &A, student &B) {
  if (A.score1 != B.score1) return A.score1 > B.score1;
  if (A.num != B.num) return A.num < B.num;
  return false;
}

bool cmp2(student &A, student &B) {
  if (A.score2 != B.score2) return A.score2 > B.score2;
  if (A.num != B.num) return A.num < B.num;
  return false;
}

bool cmp3(student &A, student &B) {
  if (A.score3 != B.score3) return A.score3 > B.score3;
  if (A.num != B.num) return A.num < B.num;
  return false;
}

void inline solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> stu[i].num >> stu[i].name >> stu[i].score1 >> stu[i].score2 >>
        stu[i].score3;
  int opt; cin >> opt;
  switch (opt) {
    case 1 : sort(stu, stu + n, cmp1); break;
    case 2 : sort(stu, stu + n, cmp2); break;
    case 3 : sort(stu, stu + n, cmp3); break;
  }
  for (int i = 0; i < n; ++i)
    cout << stu[i].num << " " << stu[i].name << " " << stu[i].score1 << " "
         << stu[i].score2 << " " << stu[i].score3 << '\n';
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