#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
string s[N];

int main() {

	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>s[i];

	int q;
	cin>>q;
	while(q--) {
		int i,j,l,r,p;
		cin>>i>>j>>l>>r>>p;
	}

	int ans=0;
	for(int i=0; i<m; i++) {
		int cnt=1;
		for(int j=0; j<n; j++)
			if(s[j][i]=='0') cnt=0;
		ans+=cnt;
	}
	cout<<ans;

	return 0;
}
