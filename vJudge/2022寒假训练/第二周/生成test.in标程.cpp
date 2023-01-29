#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("in.txt", ios::out);

int main(void) {
  int inT = 100; while (inT--) {
    int n = rand() % 100, m =rand() % 100;
    fout << m << " " << n<< endl;
    for (int i = 0; i < n; i++) fout << rand() % 1000000 << " ";
    fout << endl;
    for (int i = 0; i < m; i++) fout << rand() % 1000000 << endl;  
  }
  return 0;
  fout.close();
  return 0;
}
