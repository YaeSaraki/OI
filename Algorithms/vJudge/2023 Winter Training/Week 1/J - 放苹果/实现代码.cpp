#include <ctype.h>
#include <string.h>

#include <algorithm>
#include <iostream>


typedef long long ll;
using namespace std;

ll f(int m, int n);

int main() {
  int T; cin >> T; while (T--) {
    int m, n;
    cin >> m >> n;
    cout << f(m, n) << endl;
  }
}

ll f(int m, int n) {
  if (n == 0) return 0;
  if (m == 0) return 1;
  if (n > m) return f(m, m);
  else return f(m, n - 1) + f(m - n, n);
}