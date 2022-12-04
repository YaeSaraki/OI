#include <math.h>

#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char name[15], temp[15];
  int n, m, max = -1;
  cin >> n;
  while (n--) {
    getchar();
    cin >> name >> m;
    if (max < m) {
      max = m;
      strcat(name, "\0");
      strcpy(temp, name);
    }
  }
  cout << temp << endl;
  return 0;
}