#include <math.h>

#include <iostream>

int judge(int *a);

int main(void) {
  int T, a[5] = {0}, temp;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 4; i++)
      for (int j = i; j <= 4; j++)
        if (a[i] > a[j]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
    if (judge(a))
      printf("1");
    else
      printf("0");
    return 0;
  }
}

int judge(int *a) {
  if (a[3] <= 4) return 0;
}