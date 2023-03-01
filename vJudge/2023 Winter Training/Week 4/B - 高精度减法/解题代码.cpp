#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string sub(string str1, string str2);

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << sub(str1, str2);
  return 0;
}

string sub(string str1, string str2) {
  string str;

  int len1 = str1.length(), len2 = str2.length();
  int devation = fabs(len1 - len2);
  if (len1 < len2)
    for (int i = 1; i <= devation; ++i) str1 = "0" + str1;
  else 
    for (int i = 1; i <= devation; ++i) str2 = "0" + str2;
  if (str1 < str2) {
    swap(str1, str2), swap(len1, len2);
    cout << "-";
  }
  int down = 0;
  for (int i = len1 - 1; i >= 0; --i) {
    int temp = str1[i] - str2[i] - down;
    down = 0;
    if (temp < 0) {
      temp += 10;
      down++;
    }
    str = char(temp % 10 + '0') + str;
  }
  while (str[0] == '0' && str.length() != 1) str.erase(str.begin());
  return str;
}