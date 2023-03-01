#include <iostream>
using namespace std;
#define M 10010

int main() {
  int T, x[M], y[M], xx[M], yy[M], ax, ay, ans = -1;
  cin >> T;
  for (int i = 0; i < T; i++) cin >> x[i] >> y[i] >> xx[i] >> yy[i];
  cin >> ax >> ay;
  for (int i = T - 1; i >= 0; i--) {
    if ((x[i] <= ax && ax <= x[i] + xx[i]) &&
        (y[i] <= ay && ay <= y[i] + yy[i])) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}