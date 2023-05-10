#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int a, b, c, x1, x2, y1, y2, sum = 0;
  double x, y;
  cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
  for (x = x1; x <= x2; x++) {
    y = (1.0 * (-c - a * x)) / b;
    if (fabs(y - (int)y) <= 1e-10)
      if (y >= y1 && y <= y2) sum++;
  }
  cout << sum << endl;
  return 0;
}
//方法不对且学不会