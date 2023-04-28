#include<iostream>
#include<algorithm>
#include<fstream>
#include<string.h>
using namespace std;
//#define cin fin
//#define cout fout
//ifstream fin("in.txt");
//ofstream fout("out.txt");

int num[1001001];
int n, m, t, ans = 0;

int BinarySearch() {
	int l = 0, r = n - 1, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (num[mid] == t) {
			return 1;
		}
		if (num[mid] < t) l = mid + 1;
		else r = mid - 1;
	}
	return 0;
}

int main() {
	while (scanf("%d%d", &n, &m) && m + n) {
		ans = 0;
		for (int i = 0; i < n; ++i) scanf("%d", &num[i]); 
		for (int i = 0; i < m; ++i) {
			scanf("%d", &t); 
			ans += BinarySearch();
		}
		printf("%d\n", ans);
	}
	return 0;
}
