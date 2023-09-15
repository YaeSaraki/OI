#include <algorithm>
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
using ll = long long;

int flag = 1;
int q[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char c[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

inline void solve() {
  string id; cin >> id;
  int cnt = 0;
  for (int i = 0; i < 17; ++i) cnt += (id[i] - '0') * q[i];
  cnt %= 11;
  if (id[17] != c[cnt]) return flag = 0, cout << id << endl, void(); 
}


bool tc = true;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (tc) {int T; cin >> T; while(T--) solve(); }
  else solve();
  if (flag) cout << "All passed";
  return 0;
}