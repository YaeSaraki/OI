#include <algorithm>
#include <iostream>
using namespace std;

string number;
void insertionSort(string& str, int n);


int main() {
  cin >> number;
  insertionSort(number, number.size());
  cout << number;
  return 0;
}

void insertionSort(string& str, int n) {
  for (int i = 1; i < n; ++i) {
    int j = i - 1;
    int key = str[i];
    while (j && key < str[j]) {
      str[j + 1] = str[j];
      --j;
    }
    str[j + 1] = key;
  }
}