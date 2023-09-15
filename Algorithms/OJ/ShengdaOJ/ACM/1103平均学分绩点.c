#include <stdio.h>

int xuefen(int cj);

int main() {
  int n;
  scanf("%d", &n);
  double sumxf = 0, average = 0;
  for (int i = 1; i <= n; i++) {
    int jidian, chengji;
    scanf("%d%d", &jidian, &chengji);
    average += jidian * xuefen(chengji);
    sumxf += jidian;
  }
  average = average * 1.0 / sumxf;
  printf("%.1lf", average);
  return 0;
}

int xuefen(int cj) {
  if (cj < 60)
    return 0;
  else
    return (cj - 50) / 10;
}