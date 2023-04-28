// https://www.acwing.com/problem/content/3732/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// #define cin fin
// ifstream fin("test.in");


int main() {
  int T; cin >> T; while(T--) {
    int n; scanf("%d", &n);
    vector<int> A;
    for (int i = 0; i < n; ++i) {
      int m; scanf("%d", &m);
      A.push_back(0);
      if (m) {
        for (int i = A.size() - 1; m > 0 && i >= 0; --i, --m) A[i] = 1;
      }
    }
    for (auto it : A) printf("%d ", it);
    printf("\n");
  }
}