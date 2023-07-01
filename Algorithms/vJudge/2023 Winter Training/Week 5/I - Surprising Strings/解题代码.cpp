#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

// #define cin fin
// #define cout fout
ifstream fin("test.in");
ofstream fout("test.out");

int main() {
  string input;
  while (cin >> input) {
    int step = 1, flag = 0;
    if (input == "*") break;
    for (int i = 0; i < input.length(); ++i) {
      if (flag) break;
      map<string, int> map;
      for (int j = 0; j + i + 1 < input.length(); ++j) {
         string temp;
         temp.push_back(input[j]),temp.push_back(input[j + i + 1]);
         if (map.count(temp)) {
          flag = 1;
          cout << input << " is NOT surprising." << endl;
         } else map.insert(make_pair(temp, 1));
      }
      ++step;
    }
    if (!flag) cout << input << " is surprising." << endl;
  }
  return 0;
}