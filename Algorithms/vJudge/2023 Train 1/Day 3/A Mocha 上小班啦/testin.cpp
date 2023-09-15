#include<stdio.h>
#include<stdlib.h>
//#include<time.h>

int main(void)
{
	
	freopen("test.in.txt","w",stdout);
	//srand(time(NULL));
	int a;
	int t=30; 
	while(t--){
		a=rand()%20;
		if(a)
		printf("%d\n",a);
	}
	fclose(stdout);
	return 0;
}
