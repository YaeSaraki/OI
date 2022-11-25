#include <math.h>
#include <stdio.h>

double power(char ch);

int main() {
  char ch;
  double average = 0;
  int time = 0;
  while ((ch = getchar()) != '\n')  //不能使用EOF,会将\n带入输入缓冲区
  {
    time++;
    average += power(ch);
  }
  average *= 1.00 / time;
  printf("%.1lf\n", average);
  return 0;
}

double power(char ch) {
  switch (ch) {
    case 'A':
      return 95;
    case 'B':
      return 85;
    case 'C':
      return 75;
    case 'D':
      return 65;
    case 'E':
      return 40;
    default:
      return 0;
  }
}