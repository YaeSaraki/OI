#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

string add(string str1, string str2);
string mul(string str1, string str2);

int main() {
  int inT = 100; while (inT--) {
  string str1, str2;
  fin >> str1 >> str2;
  fout << mul(str1, str2) << endl;
  }
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
  int temp = 0, up = 0;
  int len1 = str1.length(), len2 = str2.length(), T = 0;
  for (int i = len2 - 1; i >= 0; --i) {
    string strTemp;
    int muler = str2[i] - '0';
    for (int j = len1 - 1; j >= 0; --j) {
      temp = (str1[j] - '0') * muler + up;
      up = up / 10 + temp / 10;
      strTemp = char(temp % 10 + '0') + strTemp;
    }
    while (up) {
      strTemp = char(up % 10 + '0') + strTemp;
      up /= 10;
    }
    for (int i = 1; i <= T; i++) strTemp += "0";  
    T++;
    str = add(str, strTemp);
  }
  while (str[0] == '0') str.erase(str.begin());
  if (str.empty()) str = "0";
  return str;
}