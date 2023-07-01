#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int a[100100100];

void BFS(int l, int r, int t) {
	mid = (r - l) >> 1;
	if (a[mid + 1] - a[mid] >= a[mid] - a[mid - 1]) {
		
	} 
}

int main() {
	int n; cin >> n;
	a[1] = 1;
	int i = 1;
	for (int t = 2; i <= n; ++i) {
		int num; cin >> num;
		t += num;
		a[i] = t + num;
	}
	
	cout << "0 " << a[n];
	int cnt = a[n];
	int mid = 0, l = 1. r = 5;
	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		mid = (r - l) >> 1;
		if (a[mid + 1] - a[mid] >= a[mid] - a[mid - 1])  
	}
}
