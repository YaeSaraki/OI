#include <ctype.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

void perm(string str, int m, int n);
int main() {
  string str;
  cin >> str;
  perm(str, 0, str.length());
  return 0;
}

void perm(string str, int m, int n) {
  if (m == n) {
    cout << str << endl;
  } else {
    for (int i = m; i < n; i++) {
      string temp = str; 
      swap(str[m], str[i]);
      sort(str.begin() + m + 1, str.begin() + n);
      perm(str, m + 1, n);
      str = temp;
    }
  }
}