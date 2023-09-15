#include <iostream>
#include <algorithm>
#include <set>

#define F(x, n) for (int x = 0; x <= n; ++x)

using namespace std;
using PII = pair<double, double>;
using PIII = pair<PII, double>;

set<PIII> K;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }


int main() {
  F(x1, 19) F(x2, 19) F(y1, 20) F(y2, 20) {
    if (x1 != x2 && y1 != y2) {
      double a = x2 - x1, b = y1 - y2, c = x1 * y2 - x2 * y1; 
      // 两点式方程 (y1-y2) * x +(x2-x1) * y +( x1 * y2 - x2 * y1)=0
      double m = gcd(a, gcd(b, c));
      K.insert({{a / m, b / m}, c / m});
    }
  }
  cout << K.size() + 20 + 21;
  return 0;
}