#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int b[10];

int main() {
  string numstr; cin >> numstr;
  for (auto it : numstr) ++b[it - '0'];
  for (int i = 0; i < 10; ++i) 
    if (b[i]) cout << i << ":" << b[i] << '\n';
  return 0; 
}