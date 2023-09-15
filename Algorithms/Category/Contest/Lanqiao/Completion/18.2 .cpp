#include <iostream>
#include <algorithm>
#include <bitset>
#include <fstream>

using namespace std;
#define cin fin
ifstream fin("test.in");

int main() {
  int n, m;
  while(cin >> n >> m) {
    bitset<8> b(n);
    string str1 = b.to_string();
    for (int i = 0; i < str1.length(); ++i) {
      if (str1[i] == '0') cout << " ";
      else cout << "#";
    }
    bitset<8> c(m);
    string str2 = c.to_string();
    for (int i = 0; i < str2.length(); ++i) {
      if (str2[i] == '0') cout << " ";
      else cout << "#";
    }
    cout << endl;
  }
  return 0;
}