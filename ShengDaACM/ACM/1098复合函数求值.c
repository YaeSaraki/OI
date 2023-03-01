#include <math.h>
#include <stdio.h>

double funF(double x);
double funG(double x);

int main() {
  double x, y;
  scanf("%lf", &x);
  y = funF(funG(x));
  printf("%.2lf\n", y);
  return 0;
}

double funF(double x) { return fabs(x - 3) + fabs(x + 1); }
double funG(double x) { return x * x - 3 * x; }
