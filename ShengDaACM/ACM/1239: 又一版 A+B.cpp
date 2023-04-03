#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void swap(char &a, char &b) { char t = a; a = b; b = t; }

void strrev(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; ++i) swap(str[i], str[len - 1 - i]);
}

void DTOB(long long m, long long sum1, char str[]) {
  long long len = 0;
  while (sum1) {
    str[len] = sum1 % m + '0';
    len++;
    sum1 /= m;
  }
  str[len] = '\0';
  strrev(str);
}

int main() {
  long long m, a, b;
  char str[100000];
  while (scanf("%lld", &m), m != 0) {
    scanf("%lld %lld", &a, &b);
    if (a == 0 && b == 0) {
      printf("0\n");
      continue;
    }
    long long sum1 = 0;
    sum1 = a + b;
    DTOB(m, sum1, str);
    puts(str);
  }
  return 0;
}