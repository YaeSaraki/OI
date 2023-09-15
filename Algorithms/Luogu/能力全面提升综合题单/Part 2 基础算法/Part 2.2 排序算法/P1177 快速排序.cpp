#include <iostream>

using namespace std;

int a[1000001];

void merge(int *a, int middle, int left, int right);
void mergeSort(int *a, int left, int right);

int main(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  mergeSort(a, 0, n - 1);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}

void mergeSort(int *a, int left, int right){
  if (left < right) {
    int middle = (left + right) / 2;
    mergeSort(a, left, middle), mergeSort(a, middle + 1, right);
    merge(a, middle, left, right);
  }  
}
void merge(int *a, int middle, int left, int right){
  int* temp = new int[right - left];
  int i = left, j = middle + 1, k = 0;
  while (i <= middle && j <= right) {
    if (a[i] < a[j]) temp[k++] = a[i++];
    else temp[k++] = a[j++];
  }
  while (i <= middle) temp[k++] = a[i++];
  while (j <= right) temp[k++] = a[j++];
  for (k = 0, i = left; i <= right; i++) a[i] = temp[k++];
  delete [] temp;
}



