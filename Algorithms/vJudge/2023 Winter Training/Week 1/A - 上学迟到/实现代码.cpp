#include <math.h>

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int S, V;
  cin >> S >> V;
  double T = S * 1.0 / V;
  if (V == 0) T = 0;
  int zT;
  if (fabs(T - (int)T) <= 1e-8) zT = (int)T + 10;
  else zT = (int)T + 11;
  int temp = (480 - zT + 1440) % 1440;
  printf("%02d:%02d", temp / 60, temp % 60);
  return 0;
}
