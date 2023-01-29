#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fstream>
#include <iostream>

using namespace std;

void perm(string str, int m, int n);

ofstream fout("in.txt", ios::out);

int main(void) {
  int inT = 100; while (inT--) {
    string str;
    int T = rand() % 6 + 1;
    int bucket[233] = {0};
    for (int i = 0; i < T; i++) {
      int temp = rand() % 25 + 'a';
      if (!bucket[temp]) {
        bucket[temp]--;
        str.push_back(temp);
      } else {
        i--;
        continue;
      }
    }
    fout << str << endl;  
  }
  fout.close();
  return 0;
}
