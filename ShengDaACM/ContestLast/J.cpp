#include <stdio.h>

double a[10010];
double b[10010];

int main(void) {
  int m, n, i, j, k, index;
  double t;
  double x;
  scanf("%d", &m);
  for (k = 1; k <= m; k++) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lf", &a[i]);
    for (i = 0; i < n - 1; i++)
      for (j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          t = a[i];
          a[i] = a[j];
          a[j] = t;
        }
      }
    if (n % 2 == 0)
      b[k] = (a[n / 2 - 1] + a[n / 2]) / 2;
    else
      b[k] = a[n / 2];
  }
  double sum = b[1];
  int abc = 1;
  for (i = 2; i <= n; i++) {
    if (x + 0.01 < b[i]) {
      sum = b[i];
      abc = i;
    }
  }
  printf("第%d组的疗效最好，中位数是%.2lf。\n", abc, sum);
  return 0;
}