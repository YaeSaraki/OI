#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("test.in");
ofstream fout("test.out");

int main() {
  int leftParenthesis_number = 0, rightParenthesis_number = 0, value = 0;
  string input;
  cin >> input;
  for (auto it : input) {
    if (it == '(') leftParenthesis_number++, value++;
    if (it == ')') rightParenthesis_number++, value--;
    if (value < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (leftParenthesis_number == rightParenthesis_number) cout << "YES" << endl;
  else cout << "NO" << endl;
}