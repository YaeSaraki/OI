#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    int m, sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> m;
      sum += m;
    }
    cout << sum << endl;
  }
  return 0;
}
