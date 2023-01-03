#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>

using namespace std;

int main(void) {
  freopen("in.txt", "w", stdout);
  int inT = 100;
  while (inT--) {

    int t = rand() % 21;
    cout << t << endl;
    while (t--) {
      int m = rand() % 11;
      int n = rand() % 11;
      cout << m << " " << n << endl;
    }

  }
  fclose(stdout);
  return 0;
}
