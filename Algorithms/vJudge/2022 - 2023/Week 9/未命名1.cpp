#include<iostream>
#include<cmath>
using namespace std;
double ans = 0;
int main (void)
{
	int n;
	double r,c;
	scanf("%d %lf %lf",&n,&r,&c);
	if(c > acos(-1))
	c = acos(-1) - c;
	ans = r * c;
	for(int i = 1; i <= n; i++)
	{
		double a;
		scanf("%lf",&a);
		double t = (r - a) * 2 + a * c;
		if(t < ans)
		ans = t;
	}
	printf("%lf",ans);
	return 0;
}
