// Divide and Conquer
#include <iostream>
using namespace std;

void merge(string& str,int left,int middle,int right);
void merge_sort(string& str, int left, int right);

int main(){
  string str;
  cin >> str;
  int left = 0, right = str.size() - 1;
  merge_sort(str, left, right);
  cout << str;
  return 0;
}

void merge_sort(string& str, int left, int right) {
  if (left < right) {
    int middle  = (left + right) / 2;
    merge_sort(str, left, middle), merge_sort(str, middle + 1, right);
    merge(str, left, middle, right);
  }
}

void merge(string& str, int left, int middle, int right) {
  string* temp = new string[right - left];
  int i = left, j = middle + 1, k = 0;
  while (i <= middle && j <= right) {
    if (str[i] < str[j]) (*temp)[k++] = str[i++];
    else (*temp)[k++] = str[j++];
  }
  while (i <= middle) (*temp)[k++] = str[i++];
  while (j <= right) (*temp)[k++] = str[j++];
  k = 0;
  for (int i = left; i <= right; ++i) str[i] = (*temp)[k++];
  delete[] temp;
}
