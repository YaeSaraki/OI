#include <math.h>
#include <stdio.h>

void sxhs(int m, int n);

int main() {
  int m;
  int n;
  while (scanf("%d%d", &m, &n) != EOF) {
    sxhs(m, n);
    printf("\n");
  }
  return 0;
}

void sxhs(int m, int n) {
  int a, b, c, flag = 0;
  for (int i = m; i <= n; i++) {
    if (pow(i / 100, 3) + pow(i % 100 / 10, 3) + pow(i % 10, 3) == i) {
      if (flag != 0) printf(" ");
      printf("%d", i);
      flag += 1;
    }
  }
  if (flag == 0) printf("no");
}
