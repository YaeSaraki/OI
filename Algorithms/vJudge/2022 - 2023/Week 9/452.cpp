#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std; 
const int maxn=2020;
int s[maxn+maxn],n,b,a;

int find_set(int x){ 
	return x==s[x]?x:s[x]=find_set(s[x]);
}

void union_set(int n,int b) 
{
	int fa=find_set(n);
	int fb=find_set(b);
	if(fa!=fb) s[fa]=fb;
}

void init(){ 
	for(int i=1;i<=maxn+maxn;i++) s[i]=i;
}

int main()
{	
	int t,n,m;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		init();
		int flag=0; 
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			if(flag) continue; 
			union_set(a,b+n);
			union_set(a+n,b);
			if(find_set(a)==find_set(b)) 
			{
				flag=1;
				continue;
			}	
		}
		printf("Scennrio #%d:\n",i);
		
		if(flag)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
	return 0;
}

