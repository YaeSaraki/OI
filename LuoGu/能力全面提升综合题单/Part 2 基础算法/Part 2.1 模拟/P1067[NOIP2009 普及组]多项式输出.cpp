#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int n, a;
  cin >> n;
  for (int i = n; i >= 0; i--) {
    cin >> a;
    if (a == 0) continue;
    if (a < 0) cout << "-";
    if (a > 0 && i != n) cout << "+";
    if (fabs(a) != 1 || i == 0) cout << (int)fabs(a);
    if (i) {
      cout << "x";
      if (i != 1) cout << "^" << i;
    }
  }
  return 0;
}
