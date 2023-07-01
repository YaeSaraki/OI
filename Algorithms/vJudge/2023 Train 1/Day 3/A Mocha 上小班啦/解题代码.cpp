#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n>10)
	{
		cout<<"-1"<<endl;
	}
	else if(n==1)
	{
		cout<<"1"<<endl;
	} 
	else if(n==2)
	{
		cout<<"10"<<endl;
	} 
	else if(n==3)
	{
		cout<<"102"<<endl;
	} 
	else if(n==4)
	{
		cout<<"1023"<<endl;
	} 
	else if(n==5)
	{
		cout<<"10234"<<endl;
	} 
	else if(n==6)
	{
		cout<<"102345"<<endl;
	} 
	else if(n==7)
	{
		cout<<"1023456"<<endl;
	} 
	else if(n==8)
	{
		cout<<"10234567"<<endl;
	} 
	else if(n==9)
	{
		cout<<"102345678"<<endl;
	} 
	else if(n==10)
	{
		cout<<"1023456789"<<endl;
	} 
	return 0;
}
