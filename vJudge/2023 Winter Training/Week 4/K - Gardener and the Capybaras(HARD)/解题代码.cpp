#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T; cin >> T; while (T--) {
    string nameString;
    cin >> nameString;
    int len = nameString.length();
    if (nameString[0] == 'a' && nameString[1] == 'b' && nameString[2] == 'b') {
      cout << nameString[0] << " ";
      for (int i = 1; i < len - 1; ++i) cout << nameString[i];
      cout << " " << nameString[len - 1];
    } else {
      cout << nameString[0] << " " << nameString[1] << " ";
      for (int i = 2; i < len; ++i) cout << nameString[i];
    }
    cout << endl;
  }
  return 0;
}