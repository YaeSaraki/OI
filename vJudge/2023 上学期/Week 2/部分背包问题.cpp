#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
  double weight, value, rate;
} Pile[101];

bool cmp(Node A, Node B) { return A.rate > B.rate; }

int main() {
  int n, m;
  double ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> Pile[i].weight >> Pile[i].value;
    Pile[i].rate = (Pile[i].value * 1.0) / (Pile[i].weight * 1.0);
  }
  sort(Pile, Pile + n, cmp);
  int dif;
  for (int i = 0; i < n; ++i) {
    if (m) {
      dif = m - Pile[i].weight;
      if (dif > 0) {
        m = dif;
        ans += Pile[i].value;
      } else {
        ans += Pile[i].rate * m;
        m = 0;
      }
    }
  }
  printf("%.2lf\n", ans);
}