#include <iostream>
using namespace std;

struct node {
  bool head;
  string name;
} a[100100];

int main() {
  int n, m, ai, si;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i].head >> a[i].name;
  int now = 0;
  for (int i = 1; i <= m; i++) {
    cin >> ai >> si;
    now = ai ^ a[now].head ? (now + si) % n : (now + n - si) % n;
  }
  cout << a[now].name << endl;
  return 0;
}