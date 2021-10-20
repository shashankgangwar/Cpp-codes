#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(vector<int>& a, vector<int>& b, int l, int r, int k){
	
	ll ans=0;
	for(int i=l;i<=r;i++){
		if(a[i]<=k) ans=(ll) ans + b[i];
	}
	return ans;
}

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1),s(n+1),temp_s(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		temp_s[i]=s[i];
	}
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		
		if(x==1){
			int l,r,k;
			cin>>l>>r>>k;
			cout<<solve(a,temp_s,l,r,k)<<endl;
		}
		
		else{
			int j,y;
			cin>>j>>y;
			if(y==0) temp_s[j]=0;
			else temp_s[j]=s[j];
		}
	}
	return 0;
}
