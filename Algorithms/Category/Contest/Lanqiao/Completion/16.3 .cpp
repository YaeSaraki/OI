#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int sum = 0, a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, cnt = 0;
  double res = 0;
  while (next_permutation(a + 1, a + 10)) {
    res = (double)a[1] + (double)a[2] / a[3] +
          (double)(a[4] * 100 + a[5] * 10 + a[6]) /
              (a[7] * 100 + a[8] * 10 + a[9]);
    if (res == 10.0) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}