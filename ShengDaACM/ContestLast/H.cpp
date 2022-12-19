#include <stdio.h>

int NextLeapYear(int n) {
  if ((n % 400 == 0) || (n % 100 != 0 && n % 4 == 0)) return 0;
  else {
    for (int i = n + 1;;i++) {
      if ((i % 400 == 0) || (i % 100 != 0 && i % 4 == 0)) return i;
    }
  }
}

int main()
{
  int n;
  while (scanf("%d", &n) != EOF) {
    if (NextLeapYear(n) == 0)
      printf("Never to be seperated!\n");
    else
      printf("%d\n", NextLeapYear(n));
  }
  return 0;
}