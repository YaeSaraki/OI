#include <stdio.h>
#include <math.h>

int main(){
  int m, n;
  scanf("%d%d", &m, &n);
  int max = (m > n) ? m : n;
  int s = fabs(m - n);
  printf("%d", s * max);
  return 0;
}