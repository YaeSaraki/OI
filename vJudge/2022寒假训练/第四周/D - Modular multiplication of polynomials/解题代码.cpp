#include <algorithm>
#include <iostream>

using namespace std;

int fN, gN, hN, mulN = 0;
bool cmp(bool *mul, bool *h);
int main() {
  int T; cin >> T; while (T--) {
    bool f[10010] = {0}, g[10010] = {0}, h[10010] = {0}, 
       mul[20020] = {0};

    cin >> fN;
    for (int i = fN - 1; i >= 0; --i) cin >> f[i];
    cin >> gN;
    for (int i = gN - 1; i >= 0; --i) cin >> g[i];
    cin >> hN;
    for (int i = hN - 1; i >= 0; --i) cin >> h[i];

    mulN = fN + gN - 1;
    for (int i = 0; i < gN; ++i) {
      for (int j = 0; j < fN; ++j) {
        mul[i + j] ^= (f[j] & g[i]);
      }
    }
    while (cmp(mul, h)) {
      int d = mulN - hN;
      for (int i = 0; i < mulN; ++i) mul[i + d] ^= h[i];
      while (mulN && !mul[mulN - 1]) mulN--;
    }
    if (mulN == 0) mulN = 1;
    cout << mulN << " ";
    for (int i = mulN - 1; i >= 0; --i) cout << mul[i] << " ";
    cout << endl;
  }
  return 0;
}

bool cmp(bool *mul, bool *h) {
  if (mulN < hN) return 0;
  else if (mulN > hN) return 1;
  else {
    for (int i = mulN; i >= 0; --i) {
      if (mul[i] < h[i]) return 0;
      if (mul[i] > h[i]) return 1;
    }
  return 0;
  }
}
