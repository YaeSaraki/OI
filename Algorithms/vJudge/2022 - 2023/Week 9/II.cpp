#include<iostream>
using namespace std;
long long arr[100005];
long long sum[100005];
long long ans[100005];
int main (void)
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 1; i < n;i++)
		{
			scanf("%lld",&arr[i]);
			sum[i] = sum[i-1] + arr[i];
		}
		long long res = sum[n-1];
		long long left = 0;
		for(int i = 1; i < n; i++)
		{
			if(i%2 == 0)
			{
				left++;
				ans[i] = ans[i-1] + res;
			}
			else 
			{
				res += sum[n-left-1] - sum[left];
				ans[i] = ans[i-1] + res;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(!i) printf("%lld",ans[i]);
			else printf(" %lld",ans[i]);
		}
		cout << endl;
	}
	return 0;
}
