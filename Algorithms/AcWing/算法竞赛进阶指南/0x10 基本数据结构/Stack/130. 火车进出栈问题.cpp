/**
  * \link: https://www.acwing.com/problem/content/132/ 
  * \category: 栈 卡特兰数
  * 
  *
  * \note: Pass 
  **/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n;
int times = 0;
vector<int> path, stk;

void DFS(int u) {
  /** bound */
  if (u == n) { return ++times, void(); } 
  /** 1. out of the stack. */
  if (!stk.empty()) {
    path.push_back(stk.back());
    stk.pop_back();
    DFS(u);
    stk.push_back(path.back());
    path.pop_back();
  }
  /** 2. go into the stack. */
  stk.push_back(u + 1);
  DFS(u + 1);
  stk.pop_back();
  return ;
}

inline void solve() {
  cin >> n;
  stk.reserve(20), path.reserve(20);
  DFS(0);
  return cout << times << '\n', void();
}

bool rt = false;
 int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
 }