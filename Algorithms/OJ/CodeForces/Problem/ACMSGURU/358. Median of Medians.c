// https://codeforces.com/problemsets/acmsguru/problem/99999/403
#include <stdio.h>

void sort(int a[]);

int main() {
  int a[3], b[3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &a[j]);
    }
    sort(a);
    b[i] = a[1];
  }
  sort(b);
  printf("%d", b[1]);
  return 0;
}

void sort(int *a) {
  for (int i = 0; i < 2; i++)
    for (int j = i + 1; j < 3; j++) {
      if (a[i] > a[j]) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
}