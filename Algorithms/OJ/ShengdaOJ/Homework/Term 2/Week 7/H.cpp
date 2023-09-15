#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Starr {
  int x, y;
  bool operator < (const Starr& a) const {
    if (a.x != x) return a.x < x; 
    if (a.y != y) return a.y < y;
    return false;
  }
};

set<Starr> star;

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    star.insert({x, y});
  }
  cout << star.size() << endl;
  return 0;
}