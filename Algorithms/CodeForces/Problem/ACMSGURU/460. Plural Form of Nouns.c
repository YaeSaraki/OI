// https://codeforces.com/problemsets/acmsguru/problem/99999/460
// ! strcat strlen 题目要求(没有sh转化) !
#include <stdio.h>
#include <string.h>
#define N 233
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  while (n--) {
    char str[N];
    char p1[] = "s", p2[] = "es";
    gets(str);
    int len = strlen(str) - 1;
    if (str[len] == 'o' || str[len] == 's' || str[len] == 'x' ||
        (str[len - 1] == 'c' && str[len] == 'h')) {
      strcat(str, p2);
    } else if (str[len] == 'y') {
      str[len] = 'i';
      strcat(str, p2);
    } else if (str[len] == 'f') {
      str[len] = 'v';
      strcat(str, p2);
    } else if (str[len] == 'e' && str[len - 1] == 'f') {
      str[len - 1] = 'v';
      strcat(str, p1);
    } else
      strcat(str, p1);
    puts(str);
    printf("\n");
  }
  return 0;
}