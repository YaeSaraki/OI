#include <iostream>
#include <algorithm>
using namespace std;

const int kN = 1001;

int v[kN], w[kN], f[kN];

int main() {
 int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= v[i]; --j) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }
  cout << f[m];
}

