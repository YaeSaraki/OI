// https://codeforces.com/problemsets/acmsguru/problem/99999/102
#include <math.h>
#include <stdio.h>
#include <string.h>

#define N 10000

int Coprime(int n);

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", Coprime(n));
  return 0;
}

int Coprime(int n) {
  int a[N] = {0};
  int sum = 1;
  if (n == 1) sum = 0;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      for (int j = 1; j * i < n; j++) {
        if (a[j * i] == 0) {
          a[j * i] = 1;
          sum++;
        }
      }
    }
  }
  return n - sum;
}