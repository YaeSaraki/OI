#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("in.txt", ios::out);

int main(void) {
  int inT = 100;
  while (inT--) {
    int n = rand() % (int)1e+100, m = rand() % (int)1e+100;
    fout << m << endl << n << endl;
  }
  fout.close();
  return 0;
}
