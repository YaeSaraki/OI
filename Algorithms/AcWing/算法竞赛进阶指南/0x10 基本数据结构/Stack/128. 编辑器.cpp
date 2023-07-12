/**
  * \link: https://www.acwing.com/problem/content/130/
  * \category: 栈
  * 
  * \note: Time Limits
  * 
  **/
#pragma G++ optimize(2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int now = 0;
vector<int> a;
vector<int> dst;
int cursor = 0;

void Insert() {
  int x; cin >> x;
  a.insert(next(a.begin(), cursor++), x);
  now += x;
  dst.push_back(now);
}
void Delete() {
  if (cursor) {
    now -= a.at(cursor - 1);
    a.erase(next(a.begin(), --cursor));
  }
  if (!dst.empty()) dst.pop_back();
}
void Left() {
  if (cursor) now -= a.at(--cursor);
  if (!dst.empty()) dst.pop_back();
 }
void Right() {
  if (cursor < a.size()) {
    now += a.at(cursor++);
    dst.push_back(now);
  }
}
void Q() {
  int x; cin >> x;
  // int dst[x];
  // for (auto elem : a) cout << elem << " ";
  // partial_sum(a.begin(), next(a.begin(), x), dst);
  // for (int i = 0; i < x; ++i) cout << dst[i] << " ";
  cout << *max_element(dst.begin(), next(dst.begin(), x)) << '\n';  
}

void inline solve() {
  a.reserve(1e6);
  dst.reserve(1e6);
  int q; cin >> q;
  while (q--) {
    char ch; cin >> ch;
    switch (ch) {
      case 'I': Insert(); break;
      case 'D': Delete(); break;
      case 'L': Left(); break;
      case 'R': Right(); break;
      case 'Q': Q(); break;
      default: throw "ERROR!";
    }
  }
  return ;
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
