#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(string str1, string str2);
string mul(string str1, string str2);

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << mul(str1, str2);
  return 0;
}

string add(string str1, string str2) {
  string str;
  int len1 = str1.length(), len2 = str2.length();
  int devition = fabs(len1 - len2);
  if (len1 < len2)
    for (int i = 1; i <= devition; ++i) str1 = "0" + str1;
  if (len1 > len2)
    for (int i = 1; i <= devition; ++i) str2 = "0" + str2;
  int up = 0, temp = 0;
  len1 = str1.length();
  for (int i = len1 - 1; i >= 0; --i) {
    temp = str1[i] - '0' + str2[i] - '0' + up;
    up = temp / 10;
    str = char(temp % 10 + '0') + str;
  }
  if (up) str = char(up + '0') + str;
  return str;
}

string mul(string str1, string str2) {
  string str;
  int len1 = str1.length(), len2 = str2.length(), T = 0;
  for (int i = len2 - 1; i >= 0; --i) {
    int temp = 0, up = 0;
    string strTemp;
    int muler = str2[i] - '0';
    if (muler) {
      for (int j = 1; j <= len2 - 1 - i; ++j) strTemp += "0";
      for (int j = len1 - 1; j >= 0; --j) {
        temp = (str1[j] - '0') * muler + up;
        up = up / 10 + temp / 10;
        strTemp = char(temp % 10 + '0') + strTemp;
      }
      if (up) strTemp = char(up % 10 + '0') + strTemp;
    }
    str = add(str, strTemp);
  }
  str.erase(0, str.find_first_not_of('0'));
  if (str.empty()) str = "0";
  return str;
}
