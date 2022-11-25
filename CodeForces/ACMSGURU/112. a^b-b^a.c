// https://codeforces.com/problemsets/acmsguru/problem/99999/112
#include <math.h>
#include <stdio.h>
#include <string.h>
#define N 233

void input(int n, int *a);
void mutiply(int *a, int x, int n);
int pnJudge(int a[], int b[]);
void subtract(int *a, int *b);
void output(int a[]);

int main() {
  int A, B;
  int a[N] = {0}, b[N] = {0};
  scanf("%d%d", &A, &B);
  input(A, a), input(B, b);
  mutiply(a, A, B), mutiply(b, B, A);
  // printf("%d", b[0]);
  int t = pnJudge(a, b);

  if (t == 1) {
    subtract(a, b);
    output(a);
  } else if (t == 0) {
    printf("-");
    subtract(b, a);
    output(b);
  } else {
    printf("0\n");
    return 0;
  }
  return 0;
}

void input(int n, int *a) {
  int i = 0;
  while (n != 0) {
    a[i++] = n % 10;
    n /= 10;
  }
}

void mutiply(int *a, int n, int x) {
  for (int i = 1; i < x; i++) {
    int up = 0;
    for (int j = 0; j < N; j++) {
      int t = a[j] * n;
      a[j] = (t + up) % 10;
      up = (t + up) / 10;
    }
  }
}

int pnJudge(int a[], int b[]) {
  for (int i = N - 1; i >= 0; i--) {
    if (a[i] > b[i]) return 1;
    if (a[i] < b[i]) return 0;
  }
  return -1;
}

void subtract(int *a, int *b) {
  int down = 0;
  for (int i = 0; i < N - 1; i++) {
    int t = down + b[i];
    if (a[i] >= t) {
      a[i] -= t;
      down = 0;
    } else {
      a[i] += 10;
      a[i] -= t;
      down = 1;
    }
  }
}

void output(int a[]) {
  int flag = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (a[i] > 0) flag = 1;
    if (flag == 1) {
      printf("%d", a[i]);
    }
  }
}