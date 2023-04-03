#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define cin fin
#define cout fout

ofstream fout("test.out");
ifstream fin("test.in");

string a, b;
int lena, lenb;

int main() {
  int T = 41;
  while (T--) {
    cin >> a >> b;
    lena = a.length(), lenb = b.length();
    int k1 = 0, k2 = 0;
    while (k1 < lena && a[k1] != '.') ++k1;
    while (k2 < lenb && b[k2] != '.') ++k2;
    if (k1 == lena) {
      a += ".";
      ++lena;
      while (k1 < lena && a[k1] != '.') k1++;
    }
    if (k2 == lenb) {
      b += ".";
      ++lenb;
      while (k2 < lenb && b[k2] != '.') k2++;
    }
    int f1 = abs(k1 - k2), f2 = abs(lena - k1 - 1 - (lenb - k2 - 1));
    if (k1 < k2) {
      for (int i = 0; i < f1; ++i) a = "0" + a;
    } else {
      for (int i = 0; i < f1; ++i) b = "0" + b;
    }
    if (lena - k1 - 1 < lenb - k2 - 1) {
      for (int i = 0; i < f2; ++i) a += "0";
    } else {
      for (int i = 0; i < f2; ++i) b += "0";
    }
    reverse(a.begin(), b.end());
    reverse(b.begin(), b.end());

    string res = "";
    int t = 0;
    for (int i = 0; i < a.length(); ++i) {
      if (a[i] == '.')
        res += ".";
      else {
        t += (a[i] - '0') + (b[i] - '0');
        res += to_string(t % 10);
        t /= 10;
      }
    }
    while (t) {
      res += to_string(t % 10);
      t /= 10;
    }

    int k = 0;
    int flag = res.find(".");
    while (res[k] == '0' && k + 1 < flag) ++k;
    res = res.substr(k);
    reverse(res.begin(), res.end());

    cout << res << "\n";
  }
  return 0;
}