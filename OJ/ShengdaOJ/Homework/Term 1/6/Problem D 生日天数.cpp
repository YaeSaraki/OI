#include <stdio.h>

#include <iostream>
using namespace std;

int year1, month1, day1, year2, month2, day2;
bool LeapYear(int year);
int yToD();
int mToD();

int main() {
  int T;
  while (cin >> T, T != 0) {
    if (T == 0) return 0;
    while (T--) {
      scanf("%d %d %d", &year1, &month1, &day1);
      scanf("%d %d %d", &year2, &month2, &day2);
      int day = yToD() + mToD() + day2 - day1;  //度过总天数
      printf("%d\n", day);
    }
  }
  return 0;
}

bool LeapYear(int year) {  //闰否
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 1;
  return 0;
}

int yToD() {  //计算中间度过每年的天数
  int day = 0;
  for (int i = year1 + 1; i < year2; i++) {
    if (LeapYear(i)) day++;
    day += 365;
  }
  return day;
}

int mToD() {  //度过单月的天数
  int d1 = 0, d2 = 0, d[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
  for (int i = 0; i < month2; i++) d2 += d[i];
  if ((LeapYear(year2)) && (month2 > 2)) d2++;
  for (int i = 0; i < month1; i++) d1 += d[i];
  if ((LeapYear(year1)) && (month1 > 2)) d1++;
  if (year1 == year2) return d2 - d1;
  return 365 + LeapYear(year1) - d1 + d2;
}