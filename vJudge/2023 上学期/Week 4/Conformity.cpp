#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// #define cin fin
// ifstream fin("test.in");

const int N = 5;

int main() {
  int n;
  while (cin >> n && n) {
    map<vector<int>, int> m;
    int maxn = 0;
    while (n--) {
      vector<int> v(N);
      for (int i = 0; i < N; ++i) cin >> v[i];
      sort(v.begin(), v.end());
      ++m[v];
      maxn = max(maxn, m[v]);
    }
    int cnt = 0;
    for (auto v : m) 
      if(v.second == maxn) cnt += maxn;
    cout << cnt << endl;
  }
  return 0;
}