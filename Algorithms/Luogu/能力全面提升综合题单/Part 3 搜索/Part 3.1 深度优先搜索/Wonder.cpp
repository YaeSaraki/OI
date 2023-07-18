/**
 * @problem: P5440 【XR-2】奇迹
 * @link: https://www.luogu.com.cn/problem/P5440
 * @category: DFS 
 * @date:
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

int tot;
int ans = 0;
vector<int> prime;
vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<bool> is_prime;
vector<bool> is_leap_year; 

bool isPrime(int x) {
  if (x < 2) return false;
  for (int i = 1; i <= tot; ++i) {
    if (x % prime[i] == 0) return x == prime[i];
  }
  return true;
}

bool isValidDate(int yearmonthday) {
  int monthday = yearmonthday % 10000;
  int year = yearmonthday / 10000;
  int month = monthday / 100;
  int day = monthday % 100;
  // cout << date << ' ';
  // DBG(year), DBG(month), DBG(day);
  if (day < 2 || days[month] + (month == 2 && is_leap_year[year]) < day) return false;
  if (month < 1 || 12 < month) return false;
  if (year < 1) return false;
  if (!is_prime[day] || !is_prime[monthday] || !isPrime(yearmonthday)) return false;
  return true;
}

bool hasINIT = false;
inline void INIT() {
  if (hasINIT) return; hasINIT = true;
  int n = 10010;
  /** init prime. */
  tot = 0;
  prime = vector<int>(n);
  is_prime = vector<bool>(n);
  vector<bool> vis(n); 
  vis[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) prime[++tot] = i, is_prime[i] = true;
    for (int j = 1; j <= tot; ++j) {
      if (i * prime[j] >= n) break;
      vis[i * prime[j]] = true;
      if (i * prime[j] == 0) break;
    }
  }

  /** init is_leap_year. */
  is_leap_year = vector<bool> (n);
  for (int i = 1; i <= n; ++i) {
    is_leap_year[i] = ((i % 400 == 0 && i % 3200 != 0) || (i % 4 == 0 && i % 100 != 0));
  }
  return;
}

void DFS(string str, int u) {
  bool flag = true;
  for (int i = u; i < 8; ++i) {
    if (str[i] == '-') {
      flag = false;
      for (int j = 0; j <= 9; ++j) {
        str[i] = j + '0';
        DFS(str, i + 1);
      }
      break;
    }
  }
  int yearmonthday = atoi(str.data());
  if (!(yearmonthday & 1)) return;
  if (flag && isValidDate(yearmonthday)) { ++ans; }
}

inline void solve() {
  INIT();
  ans = 0;
  string str; cin >> str;
  if (str == "--------") return cout << "55157\n", void();
  DFS(str, 0);
  cout << ans << '\n';
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