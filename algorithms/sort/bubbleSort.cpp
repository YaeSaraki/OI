#include <iostream>
#include <algorithm>
using namespace std;

string number;
void bubbleSort(string& str, int n);

int main(){
  cin >> number;
  bubbleSort(number, number.size());
  cout << number;
  return 0;
}

void bubbleSort(string& str, int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (str[i] > str[j]) swap(str[i], str[j]);
    }
  }
}
