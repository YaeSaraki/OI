#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
  int n; scanf("%d", &n);
  double a = 50.0;
  if (n <= 30) {
    printf("%.2lf\n", n * a);
  } else {
    printf("%.2lf\n", (a - 2) * n);
  }
  return 0;
}