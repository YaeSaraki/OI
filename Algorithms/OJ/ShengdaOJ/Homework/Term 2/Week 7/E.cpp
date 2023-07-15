#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

struct student {
  string name;
  int year, month, day;
} stu[100];

bool cmp(student A, student B) {
  if (A.month != B.month) return A.month < B.month;
  if (A.day != B.day) return A.day < B.day;
  return false;
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i)  cin >> stu[i].name >> stu[i].year >> stu[i].month >> stu[i].day;
  sort(stu, stu + n, cmp);
  for (int i = 0; i < n; ++i) printf("%s %04d-%02d-%02d\n", stu[i].name.data(), stu[i].year, stu[i].month, stu[i].day);
  return 0;
}