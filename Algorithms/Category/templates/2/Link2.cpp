#include <iostream>
using namespace std;

const int N = 100100;

int l[N], r[N], e[N], idx;

void init() { r[0] = 1, l[1] = 0, idx = 2; }
void removepo(int k) {
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}
void insert(int k, int x) {
  e[idx] = x;
  r[idx] = r[k];
  l[idx] = k;
  l[r[k]] = idx;
  r[k] = idx++;
}

int main() {
  
}