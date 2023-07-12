/**
 * \link: https://ac.nowcoder.com/acm/problem/15029
 * \category: stack
 *
 * \date: Wed Jul 12 08:31:30 CST 2023 : 20mins
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

static bool kMultipleInstances = true;

void MergeBubble(stack<char> &bubble, char ch) {
  if (bubble.empty()) { bubble.push(ch); return; }
  char now = bubble.top();
  if (now != ch) {
    bubble.push(ch);
  } else {
    if (now == 'o') {
      bubble.pop();
      MergeBubble(bubble, 'O');
    }
    if (now == 'O') {
      bubble.pop();
    }
  }
  return;
}

inline void solve() {
  while (kMultipleInstances) {
    string str; cin >> str;
    if (str == "") break;
    stack<char> bubble;
    for (int i = 0; i < str.length(); ++i) {
      MergeBubble(bubble, str.at(i));
    }
    string ans;
    /** string can use +- operations
     * //while (!bubble.empty()) { ans.push_back(bubble.top()); bubble.pop(); }
     * //reverse(ans.begin(), ans.end());
     **/
    while (!bubble.empty()) { ans = bubble.top() + ans; bubble.pop();} // better.
    cout << ans << '\n';
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

