#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string str; getline(cin, str);
  string tmp; getline(cin, tmp);
  for (int i = 0; i < tmp.length(); ++i) {
    for (int j = 0; j < str.length(); ++j) {
      if (tmp[i] == str[j]) str.erase(j, 1), --j;
    }
  }
  cout << str << endl;
  return 0;
}