/**
 * \link: https://www.acwing.com/problem/content/97/
 * \category: 位运算 递推
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>

const int kN = 5;
char a[kN][kN], backup[kN][kN];

using namespace std;

void Turn(int x, int y) {
  int dx[5] = {1, 0, 0, 0, -1}, dy[5] = {0, 1, 0, -1, 0};
  for (int i = 0; i < 5; ++i) {
    int x_next = x + dx[i], y_next = y + dy[i];
    if (x_next < 0 || 5 <= x_next || y_next < 0 || 5 <= y_next) continue;
    a[y_next][x_next] ^= 1; //! ASCALL码特例, '0'和‘1’的ASCALL码与1异或可互相替换
  }
}

inline void solve() {
  for (int i = 0; i < 5; ++i) cin >> a[i];
  int ans = 7; // 设6为最大步数,对应输出-1.
  for (int op = 0; op < 32; ++op) {
    memcpy(backup, a, sizeof a);
    int step = 0;
    for (int i = 0; i < 5; ++i) {
      if (op >> i & 1) {
        Turn(i, 0);
        ++step;
      }
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (a[i][j] == '0') {
          Turn(j, i + 1);
          ++step;
        }
      }
    }
    bool flag = true;
    for (int i = 0; i < 5; ++i) {
      if (a[4][i] == '0') {
        flag = false;
        break;
      }
    }
    if (flag) ans = min(ans, step);
    memcpy(a, backup, sizeof backup);
  }
  if (ans == 7) return cout << "-1\n", void();
  else return cout << ans << '\n', void();
}

bool rt = true;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}