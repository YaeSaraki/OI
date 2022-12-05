#include <bits/stdc++.h>
using namespace std;

long long f[233] = {0, 1, 2, 3, 4};

int main() {
  for (int i = 5; i <= 233; i++) f[i] = f[i - 1] + f[i - 3];
  int n;
  while (cin >> n, n != 0) cout << f[n] << endl;
  return 0;
}