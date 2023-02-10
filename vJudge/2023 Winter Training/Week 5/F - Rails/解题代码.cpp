#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

// #define cin fin
// #define cout fout
ifstream fin("test.in");
ofstream fout("test.out");

bool isConform (stack<int>& coacheSequence, int n);

int main() {
  bool changeCoachesNumber = true;
  int haveEmptyLine = 0;
  while (changeCoachesNumber) {
    if (haveEmptyLine++) cout << endl;
    int n, m; cin >> n; 
    while (n != 0) {
      stack<int>  coacheSequence;
      cin >> m; if (!m) break; 
      coacheSequence.push(m);
      for (int i = 2; i <= n; ++i) {
        cin >> m; coacheSequence.push(m);
      } 
      if (isConform(coacheSequence, n)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    if (n == 0) return 0;
  }
  return 0;
}

bool isConform (stack<int>& coacheSequence, int n) {
  stack<int> cStation;
  int sequence = n;
  while (!coacheSequence.empty() || !cStation.empty()) {
    if (!coacheSequence.empty() && coacheSequence.top() == sequence) {
      coacheSequence.pop();
      sequence--;
      continue;
    }
    if (!cStation.empty() && cStation.top() == sequence) {
      cStation.pop();
      sequence--;
      continue;
    }
    if (!coacheSequence.empty()) {
      cStation.push(coacheSequence.top());
      coacheSequence.pop();
      continue;
    }
    return false;
  }
  return true;
}