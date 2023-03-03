#include <iostream>
using namespace std;
int a[5];
void click(int *a, int n);
int pass(int a[], int flag);

int main() {
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++)
      for (int k = 1; k <= 4; k++)
        for (int l = 1; l <= 4; l++) {
          if (a[1] + l == a[2] == a[3] == a[4]) {
          }
          if (a[1] == a[2] + k == a[3] == a[4]) {
          }
          if (a[1] == a[2] == a[3] + j == a[4]) {
          }
          if (a[1] + l == a[2] == a[3] == a[4] + i) {
          }
        }
}

void click(int *a, int n) {
  a[n - 1] = (a[n - 1] + 1) % 5;
  a[n] = (a[n] + 1) % 5;
  a[n + 1] = (a[n + 1] + 1) % 5;
}
