#include <math.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

string add(string str1, string str2);
string mul(string str1, string str2);
string exponentiation(string base, int exponent);

int main() {
  string input;
  int exponent, point;
  while (cin >> input >> exponent) {
    if (exponent == 1)
      cout << input << endl;
    else {
      point = input.find('.');
      input.erase(point, 1);
      point = input.length() - point;
      while (input[0] == '0') input.erase(input.begin());
      while (input[input.length() - 1] == '0') input.erase(input.end() - 1);
      string answer_without_point = exponentiation(input, exponent);
      
    }
  }
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

string exponentiation(string base, int exponent) {
  string str = "1";
  while (exponent) {
    if (exponent & 1) str = mul(str, base);
    base = mul(base, base);
    exponent >>= 1;
  }
  return str;
}