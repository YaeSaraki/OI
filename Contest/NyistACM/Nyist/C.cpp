#include <bits/stdc++.h>
using namespace std;

int a[10010];

int main() {
  int N, M;

  cin >> N >> M;
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  while (M--) {
    int t1 = -1, t2 = -1, t3 = -1, t4 = -1, t5 = -1, t6 = -1, flag = 1;
    cin >> t1;
    if (t1 == 1) {
      cin >> t2 >> t3;
      for (int i = 0; i < N; i++) {
        if (a[i] == t2) {
          t4 = i;
        }
        if (a[i] == t3) {
          t5 = i;
        }
      }
      if (t4 != -1 && t5 != -1)
        swap(a[t4], a[t5]);
      else
        flag = -1;
    }
    if (t1 == 2) {
      cin >> t2 >> t3;
      for (int i = 0; i < N; i++) {
        if (a[i] == t2) t4 = i;
      }
      if (t3 == 1) {
        if (t4 - 1 >= 0)
          cout << a[t4 - 1] << endl;
        else
          cout << "NULL" << endl;
      }
      if (t3 == 2) {
        if (t4 + 1 < N && t4 + 1 >= 0)
          cout << a[t4 + 1] << endl;
        else
          cout << "NULL" << endl;
      }
    }
  }
  return 0;
}