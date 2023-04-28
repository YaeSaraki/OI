#include <bits/stdc++.h>
using namespace std;

int f[100] = {0, 1, 1};

int main() {
  int n;
  cin >> n;
  for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
  cout << f[n] << endl;
  return 0;
}