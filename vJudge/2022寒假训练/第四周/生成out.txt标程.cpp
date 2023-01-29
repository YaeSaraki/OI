#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("in.txt", ios::in);
ofstream fout("out.txt", ios::out);

string add(string str1, string str2);

int main() {
  int inT = 100; while (inT--) {
  string str1, str2;
  fin >> str1 >> str2;
  fout << add(str1, str2) << endl;
  }
  return 0;
}

string add(string str1, string str2) {
  string str;
  int len1 = str1.length(), len2 = str2.length();
  int deviation = fabs(len1 - len2);  // 长度差 补齐零
  if (len1 < len2)
    for (int i = 1; i <= deviation; ++i) str1 = "0" + str1;
  if (len1 > len2)
    for (int i = 1; i <= deviation; ++i) str2 = "0" + str2;
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
