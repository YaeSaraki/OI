#include<stdio.h>
#include<math.h>
int prime(int m);
 
int main()
{
	int i,n,flag;
	while(scanf("%d",&n) != 0)
	{
		flag = 0;
		if(prime(n) == 1)
		{
			if(prime(n-2) == 1)
				flag += 1;
			else if(prime(n+2) == 1)
				flag += 1;
		}
		if(n == 2)
			flag = 0;
		if(flag >= 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
int prime(int m)
{
	int i,k;
	k = (int)sqrt(m);
	for(i = 2; i <= k; i++)
		if(m % i == 0)
		{
			return 0;
			break;
		}
	return 1;
}
