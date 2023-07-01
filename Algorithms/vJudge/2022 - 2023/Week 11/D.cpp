#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	double a,b,r,d;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b>>r>>d;
		if(atan(b/(a+r)) <= d*acos(-1) / 180)
			printf("%.12lf\n",sqrt((a+r)*(a+r)+b*b)-r);
		else
			printf("%.12lf\n",a*cos(acos(-1)*d/180)+b*sin(acos(-1)*d/180)+r*cos(acos(-1)*d/180)-r);
	}
 	return 0;
}
