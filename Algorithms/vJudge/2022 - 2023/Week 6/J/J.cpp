#include <algorithm>
#include <fstream>
#include <iostream>

// ofstream fout("test.in");
// #define cout fout

// int main() {
//   int T = 100;
//   while (T--) {
//     cout << rand() % 1000000 << endl;
//   }
// }
using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

#define cin fin
#define cout fout


const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

int init() {
  st[1] = true;
  for (int i = 2; i <= 100000; ++i) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= 1000000 / i; ++j) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

int main() {
  init();
  int T = 100;
  while (T--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; ++i) {
      ++cnt;
      cout << 1LL * primes[i] * primes[i] << "\n";
    }
    if (!cnt) cout << -1 << "\n";
  }
  return 0;
}