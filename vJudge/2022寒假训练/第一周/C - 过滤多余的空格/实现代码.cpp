#include <math.h>

#include <algorithm>
#include <iostream>
#include <cstring>


using namespace std;

string str;

int main() {
  getline(cin,str);
  int len = str.length();
  for (string::iterator it = str.begin(); it < str.end() - 1; it++) {
    while (*it == ' ' && *(it + 1) == ' ') {
      str.erase(it);
    }
  }
  cout << str;
  return 0;
}
