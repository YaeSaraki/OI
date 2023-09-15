#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#define endl '\n'

using namespace std;
using ll = long long;

string n[11] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "fu"};

inline void solve() {
  char ch;
  bool flag = 0;
  while (cin >> ch) {
    if (flag) cout << " ";
    if(ch == '-') cout << "fu";
    else cout << n[ch - '0'];
    flag = 1;
  }
  return;
}


int tc = false;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (tc) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}