#include <algorithm>
#include <iostream>
using namespace std;

string number;
void shellSort(string& str, int n);

int main() {
  cin >> number;
  shellSort(number, number.size());
  cout << number;
  return 0;
}

void shellSort(string& str, int n) {
  for (int gap = n / 2; gap >= 1; gap /= 2) {
    for (int i = gap; i < n; ++i) {
      if (str[i] < str[i - gap]) {
        int j, key = str[i];
        for (j = i - gap; j >= 0 && key < str[j]; j -= gap) {
          str[j + gap] = str[j];
        }
        str[j + gap] = key;
      }
    }
  }
}