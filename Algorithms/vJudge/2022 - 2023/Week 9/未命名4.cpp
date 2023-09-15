#include<iostream>
using namespace std;
void solve()
{
	int x,t,k,n,d;
	int f=1;
	cin >>x >> t >> k >> n >> d;
	int a[200005];
	for(int i = 1; i <= n; i++)
	{
		int c;
		scanf("%d",&c);
		if(c <= d)
		a[i] = -1;
		else
		a[i] = 1;
		a[n+i] = a[i];
	}
	n = n * 2;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
	}
	if(sum < 0) {
		puts("YES");
		return ;
	}
	int ans = 0;
	int time = 0;
	for(int i = 1; i <= n; i++)
	{
		x += a[i];
		if(x<=k)
		{
			time++;
			if(time==t)
			{
				f=0;
				cout<<"YES"<<endl;
				return ;
			}
		}
		else
		time=0;
	}
	if(sum == 0 && x == k)
	{
		for(int i = 1; i <= n; i++)
		{
			x += a[i];
			if(x > k)
			puts("YES");
		}
	}
	puts("NO");
}
int main (void)
{
	int t;
	cin >> t;
	while(t--)
	solve();
	return 0;
}
