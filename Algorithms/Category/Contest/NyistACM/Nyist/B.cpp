#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
  int n, a, b, c, d, sum = 0, flag = 0;
  cin >> n >> a >> b >> c >> d;
  cin >> str;
  int at = 0, bt = 0, gt = 0;
  for (int i = 0; i < n; i++) {
    if (!flag) at = 0, bt = 0, gt = 0;
    flag = 0;
    if (str[i] == 'A') {
      if (a >= d) {
        if (bt < 2) {
          bt++;
          at = 0, gt = 0;
          sum += a;
          flag = 1;
        } else if (bt >= 2 && at < 2) {
          at++;
          bt = 0, gt = 0;
          sum += d;
          flag = 1;
        }
      } else if (a < d) {
        if (at < 2) {
          at++;
          bt = 0, gt = 0;
          sum += d;
          flag = 1;
        } else if (at >= 2 && bt < 2) {
          bt++;
          at = 0, gt = 0;
          sum += a;
          flag = 1;
        }
      }

    } else if (str[i] == 'B') {
      if (c >= d) {
        if (gt < 2) {
          gt++;
          at = 0, bt = 0;
          sum += c;
          flag = 1;
        } else if (gt >= 2 && bt < 2) {
          bt++;
          at = 0, gt = 0;
          sum += d;
          flag = 1;
        }
      } else if (c < d) {
        if (bt < 2) {
          bt++;
          at = 0, gt = 0;
          sum += d;
          flag = 1;
        } else if (bt >= 2 && gt < 2) {
          gt++;
          at = 0, bt = 0;
          sum += c;
          flag = 1;
        }
      }

    } else if (str[i] == 'G') {
      if (at < 2) {
        at++;
        gt = 0, bt = 0;
        sum += b;
        flag = 1;
      }
    }
  }
  cout << sum << endl;
}