#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char a[4001][4001];


int main(void)
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int n; 

	while (~scanf("%d",&n)) 
	{
		getchar();
	    if(n==2 || n == 4)
		cout<<"-1"<<endl;
		else {
		if(n%2==0) {
			cout << n / 2  << endl;
			cout<<"0"<<" ";
			for(int i=2; i<=n/2; i++) {
				cout<<i<<" ";
			}
		} else {
			cout << n / 2 + 1 << endl;
			for(int i=1; i<=n/2+1; i++)
				cout<<i + 1<<" ";
		}
		}
		cout<<endl<<endl;
		getchar();
   }
	
    
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
