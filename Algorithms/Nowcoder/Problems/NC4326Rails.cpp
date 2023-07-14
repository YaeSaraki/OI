/**
 * \link: https://ac.nowcoder.com/acm/problem/14326
 * \category: 栈 
 *
 * \date: Tue Jul 11 22:16:56 CST 2023
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <stack>

//#define ONLINE_JUDGE

using namespace std;

static bool kChangeCoachesNumber= true;

bool isConform(stack<int> &coache, int n) {
  stack<int> station;
  int sequence = n;
  while (!station.empty() || !coache.empty()) {
    if (!coache.empty() && coache.top() == sequence) {
      --sequence;
      coache.pop();
      continue;
    }
    if (!station.empty() && station.top() == sequence) {
      --sequence;
      station.pop();
      continue;
    }
    if (!coache.empty()) {
      station.push(coache.top());
      coache.pop();
      continue;
    }
    return false;
  }
  return true;
}

inline void solve() {
  int haveEmptyLine = 0;
  while (kChangeCoachesNumber) {
    if (haveEmptyLine++) cout << '\n';
    int n; cin >> n;
    if (n == 0) return;
    while (n) {
      stack<int> coache;
      int x; cin >> x;
      if (x == 0) break;
      coache.push(x);
      for (int i = 1; i < n ; ++i) { cin >> x; coache.push(x); }
      if (isConform(coache, n)) cout << "Yes\n";
      else cout << "No\n";
    }
  }
  return;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
