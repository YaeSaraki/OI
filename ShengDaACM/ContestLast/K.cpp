#include <math.h>

#include <iostream>
using namespace std;

int main() {
  long long n, k;
  double p1, p2;
  cin >> n >> k;
  p1 = 1.0 / (n - 1);
  p2 = 1.0 / (n - 1 - k);
  if (p1 < p2) cout << "Why not" << endl;
  if (p1 > p2) cout << "Why are you so serious" << endl;
  if (p1 == p2) cout <<  "Whatever" << endl;
  return 0;
}