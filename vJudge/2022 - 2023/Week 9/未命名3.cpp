#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int a[100100100];

int main() {
	int n, k; cin >> n >> k;
	int x;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int ans = 0;
	int t = 0;
	int res = a[0];
	for (int i = 1; i < n; ++i) {
		if(a[i] <= res)
		{
			t++;
			if(t >= k)
			{
				printf("%d",ans+1);
				return 0;
			}
		}
		else
		{
			res = a[i];
			ans = i;
			t = 0;
		}	
	}
	printf("%d",ans+1); 
	return 0;
}
