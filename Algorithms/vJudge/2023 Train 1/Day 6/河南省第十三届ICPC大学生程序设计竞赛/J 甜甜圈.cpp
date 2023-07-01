#pragma GCC optimize(3, "Ofast", "inline")

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #define ONLINE_JUDGE
const int kN = 1e5 + 233;
priority_queue<int> mq;
// void dbg(string str) { cout << str << ' '; }
vector<int> q1(kN), q2(kN);
inline void solve() {
  int n1, n2; cin >> n1 >> n2;
  q1.resize(n1), q2.resize(n2);    // ! 必须准确定义vector数据
  for (int i = n1 - 1; i >= 0; --i) { int x; cin >> q1[i]; mq.push(q1[i]); }
  for (int i = n2 - 1; i >= 0; --i) { int x; cin >> q2[i]; mq.push(q2[i]); }
  int step = 0;
  while (!q1.empty() || !q2.empty()) {
    if (mq.top() == *max_element(q1.begin(), q1.end())) {
      // cout << " " << *max_element(q1.begin(), q1.end()) << " ";
      while (q1.back() != mq.top()) {
        // dbg(to_string(q1.back()));
        q2.push_back(q1.back());
        q1.pop_back();
        ++step;
      }
      mq.pop(); q1.pop_back();
    }
    if (mq.top() == *max_element(q2.begin(), q2.end())) {
      while (q2.back() != mq.top()) {
        q1.push_back(q2.back());
        q2.pop_back();
        ++step;
      }
      mq.pop(); q2.pop_back();
    }
  }
  return cout << step << '\n', void();
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}