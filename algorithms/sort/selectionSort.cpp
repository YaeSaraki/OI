#include <algorithm>
#include <iostream>
using namespace std;

string number;
void selectionSort(string& str, int n);

int main() {
  cin >> number;
  selectionSort(number, number.size());
  cout << number;
  return 0;
}

void selectionSort(string& str, int n) {
  for (int i = 0; i < n - 1; ++i) {
    int mNum = i;
    for (int j = i + 1; j < n; ++j) {
      if (str[j] < str[i]) mNum = j;
    }
    swap(str[i], str[mNum]);
  }
}