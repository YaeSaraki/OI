#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  double ans = 0, times = 1, num = 0;
  string str; cin >> str;
  int len = str.length();
  if (str[0] == '-') --len, times *= 1.5;
  if (!(*(str.end() - 1) & 1)) times *= 2;
  for (auto it : str) if (it == '2') ++num;
// cout << num << " " << len << " " << times << endl;
  printf("%.2lf%%", num * 1.0 / len * times * 100);
  return 0;
}