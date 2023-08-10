#include <stdio.h>

int main() {
  int P, M, C;
  int K, R, V;
  scanf("%d%d%d", &P, &M, &C);
  scanf("%d%d%d", &K, &R, &V);
  int min = P / K;
  min = (min < M / R) ? min : M / R;
  min = (min < C / V) ? min : C / V;
  printf("%d", min);
  return 0;
}