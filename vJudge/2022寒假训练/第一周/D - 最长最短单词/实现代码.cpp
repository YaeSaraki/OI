#include <limits.h>
#include <math.h>

#include <algorithm>
#include <iostream>

using namespace std;

string words;
int wmax = INT_MIN, wmin = INT_MAX, wmax_pos, wmin_pos;
int main() {
  getline(cin, words);
  for (int i = 0; i < words.length(); ++i) {
    int j = 0;
    while (words[i] != ' ' && i < words.length()) {
      j++, i++;
    }
    if (wmax < j) {
      wmax = j;
      wmax_pos = i;
    }
    if (wmin > j) {
      wmin = j;
      wmin_pos = i;
    }
  }
  for (int i = wmax_pos - wmax; i < wmax_pos; ++i) cout << words[i];
  cout << endl;
  for (int i = wmin_pos - wmin; i < wmin_pos; ++i) cout << words[i];
  return 0;
}
