#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  map<string, string> mp;
  for (int i = 0; i < n; ++i) {
    string a, b; cin >> a >> b;
    mp[a] = b, mp[b] = a;
  }
  while (m--) {
    string in; cin >> in;
    if (mp[in] == "") cout << "jlstxdyJ" << "\n";
    else cout << mp[in] << "\n";
  }
  return 0;
}
