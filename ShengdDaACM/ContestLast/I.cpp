#include <math.h>

#include <iostream>
using namespace std;
int main() {
  double x;
  int n;
  cin >> n;
  double maxk = (int)((n * 1.0 / 52 - 7) / 21);
  for (int i = 1; i <= maxk; i++) {
    x = ((n * 1.0) / 52 - 21 * i) / 7;
    if (x <= 100) {
      cout << x << " " << i << endl;
      break;
    }
  }
  return 0;
}
