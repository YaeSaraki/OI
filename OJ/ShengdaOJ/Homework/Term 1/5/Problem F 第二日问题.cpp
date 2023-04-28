#include <iostream>
using namespace std;

char a[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool LeapYear(long long int y);

int main() {
  long long int year;
  int month, day;
  while (scanf("%lld", &year), year != 0) {
    scanf("%d%d", &month, &day);
    if (++day > a[LeapYear(year)][month]) day = 1, month++;
    if (month > 12) month = 1,year++;
    printf("%lld %d %d\n", year, month, day);
  }
  return 0;
}

bool LeapYear(long long int y) {
  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return 1;
  return 0;
}
