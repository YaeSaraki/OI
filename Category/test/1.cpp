#include<stdio.h>
struct ab
{
	long long m;
	char n[20];
	int a;
	int b;
	int c;
 } a[100];
 int main()
 {
 	int n,c,d,i,b[100];
 	scanf("%d",&n);
    for(i=0;i<n;i++)
 	{
 	scanf("%lld %s %d %d %d",&a[i].m,a[i].n,&a[i].a,&a[i].b,&a[i].c);
 	b[i]=a[i].a+a[i].b+a[i].c;
    }
    for(i=1,d=0;i<n;i++)
    {
    	if(b[0]<b[i])
    	{
    		c=b[0];
			b[0]=b[i];
			b[i]=c;
			d=i; 
		}
	}
	printf("%lld %s %d %d %d",a[d].m,a[d].n,a[d].a,a[d].b,a[d].c);
	return 0; 
 }
 