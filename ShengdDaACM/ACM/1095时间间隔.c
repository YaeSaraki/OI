#include <math.h>
#include <stdio.h>

int HmsToS(int h, int m, int s);
void PrintTime(int t);

int main() {
  int h, m, s, a, b;
  while (scanf("%d:%d:%d", &h, &m, &s) != EOF) {
    a = HmsToS(h, m, s);
    scanf("%d:%d:%d", &h, &m, &s);
    b = HmsToS(h, m, s);
    PrintTime(b - a);
  }
  return 0;
}

int HmsToS(int h, int m, int s) { return h * 3600 + m * 60 + s; }

void PrintTime(int t) {
  int h, m, s;
  h = t / 3600;
  t %= 3600;
  m = t / 60;
  t %= 60;
  printf("%02d:%02d:%02d\n", h, m, t);
}