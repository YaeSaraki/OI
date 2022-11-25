#include <stdio.h>

#include <iostream>
using namespace std;

int year1, month1, day1, year2, month2, day2;
bool LeapYear(int year);
int yToD();
int mToD();

int main() {
  scanf("%d-%d-%d", &year1, &month1, &day1);
  scanf("%d-%d-%d", &year2, &month2, &day2);
  int day = yToD() + mToD() + day2 - day1;//度过总天数
  int judge = day % 5;//判断打鱼还是晒网
  if (0 < judge && judge < 4)
    cout << "He is fishing." << endl;
  else
    cout << "He is drying the net." << endl;
  return 0;
}

bool LeapYear(int year) {//闰否
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
  return false;
}

int yToD() {//计算度过每年的天数
  int day = 0;
  for (int i = year1 + 1; i <= year2; i++) {
    if (LeapYear(i)) day++;
    day += 365;
  }
  return day;
}

int mToD() {//度过单月的天数
  int day = 365, d[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
  for (int i = 0; i < month1; i++) day -= d[i];
  if (LeapYear(year1) && (month1 < 3) && (month1 != 2 || day != 29)) day++;
  for (int i = 0; i < month2; i++) day += d[i];
  if ((LeapYear(year2)) && (month2 > 2)) day++;
  return day;
}