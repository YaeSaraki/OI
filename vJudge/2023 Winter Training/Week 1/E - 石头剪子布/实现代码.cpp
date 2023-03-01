#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string p1, p2;

int main() {
  int T; cin >> T; while (T--) {
    int flag = -1;
    cin >> p1 >> p2;
    if (strcmp(p1.data(), p2.data()) == 0) flag = 0;
    
    if (strcmp(p1.data(), "Rock") == 0) {
      if (strcmp(p2.data(), "Scissors") == 0) flag = 1;
      if (strcmp(p2.data(), "Paper") == 0) flag = 2;
    }
    if (strcmp(p1.data(), "Scissors") == 0) {
      if (strcmp(p2.data(), "Rock") == 0) flag = 2;
      if (strcmp(p2.data(), "Paper") == 0) flag = 1;
    }
    if (strcmp(p1.data(), "Paper") == 0) {
      if (strcmp(p2.data(), "Scissors") == 0) flag = 2;
      if (strcmp(p2.data(), "Rock") == 0) flag = 1;
    }
    if (flag == 1) cout << "Player1" << endl;
    if (flag == 2) cout << "Player2" << endl;
    if (flag == 0) cout << "Tie" << endl;
  }
  return 0;
}