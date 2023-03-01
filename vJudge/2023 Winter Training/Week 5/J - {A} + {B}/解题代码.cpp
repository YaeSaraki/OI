#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("test.in");
ofstream fout("test.out");

int main() {
  int m, n, x;
  set<int> s;
  while (cin >> m >> n) {
    s.clear();
    for (int i = 1; i <= m + n; ++i) {
      cin >> x;
      s.insert(x);
    }
    size_t step = 1;
    for (auto it : s) {
      cout << it;
      if (step++ < s.size()) cout << " ";
    }
    cout << endl;
  }
  return 0;
}