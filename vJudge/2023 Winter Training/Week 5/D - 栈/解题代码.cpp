#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;
using ull = unsigned long long;

// #define cin fin
// #define cout fout
// ifstream fin("test.in", ios::in);
// ofstream fout("test.out", ios::out);

int main() {
  int n;
  while (cin >> n) {
    stack<ull> stack;
    while (n--) {
      string command;
      cin >> command;
      if (command == "push") {
        ull n;
        cin >> n;
        stack.push(n);
      }
      if (command == "pop") {
        stack.pop();
      }
      if (command == "sum") {
        cout << stack.size() << endl;
      }
      if (command == "out") {
        while (!stack.empty()) {
          cout << stack.top() << endl;
          stack.pop();
        }
      }
    }
    while (!stack.empty()) stack.pop();
  }
  return 0;
}