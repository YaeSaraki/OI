#include<bits/stdc++.h>
using namespace std;


int main(void)
{
	int a,b,c,d,i,t=10;
	char s[]="+-*/+-*/+-/*.@*++*#++-$-*/+%++/*-+.**-/.+**.&^+*//*/*/%>++->+-*/>";
	freopen("test.in","w",stdout);
	srand(time(NULL));
	while(t--){
		a=rand()%100;
		b=rand()%100;
		
		cout<<a<<" "<<b<<endl;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++)
			{
				c=rand()%2;
				cout<<c;
			}
			cout<<endl;
			
		}
	}
	fclose(stdout);
	return 0;
}
