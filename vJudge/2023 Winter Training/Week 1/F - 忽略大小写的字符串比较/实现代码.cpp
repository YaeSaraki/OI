#include <ctype.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

string p1, p2;

int main() {
  getline(cin, p1), getline(cin, p2);
  for (int i = 0; i < p1.length(); ++i) {
    if (isupper(p1[i])) p1[i] = tolower(p1[i]);
  }
  for (int i = 0; i < p2.length(); ++i) {
    if (isupper(p2[i])) p2[i] = tolower(p2[i]);
  }
  int state = strcmp(p1.data(), p2.data());
  if (state == 0) cout << "=";
  if (state < 0) cout << "<";
  if (state > 0) cout << ">";
  return 0;
}