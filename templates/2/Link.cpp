#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100100;

int e[N], ne[N], idx, head;
void init() { head = -1, idx = 0; }
void removepo(int k) { ne[k] = ne[ne[k]]; }
void insert_to_head(int x) {
  e[idx] = x;
  ne[idx] = head;
  head = idx++;
}
void insert(int k, int x) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx++;
}