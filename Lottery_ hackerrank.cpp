/*

Find Kth smallest lexographical permutation of 10 digits such that no two same integers are adjacent. eg:- 01223067 is not valid because tow 2 are adjacent;

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(int n, int k){
	if(k==1) return n;
	if(k==0) return 1;
	if(n<=1) return n;
	if(k%2==0){
		ll ans= power(n,k/2);
		return ans*ans;
	}
	return n*power(n,k-1);
}


string solve(ll k,int n, int prev){
	if(n==0) return "";
	
	if(k==1){
		int x;
		if(prev==0) x=1;
		else x=0;
		string ans;
		for(int i=0;i<n;i++){
			ans.push_back(x + '0');
			x=x^1;
		}
		return ans;
	}
	
	if(k==0){
		int x;
		if(prev==9) x=8;
		else x=9;
		string ans;
		for(int i=0;i<n;i++){
			ans.push_back(x + '0');
			if(x==9) x=8;
			else x=9;
		}
		return ans;
	}
	
	ll z=power(9,n-1);
	int y= k/z;
	if(k%z==0) y--;
	if(prev<=y) y++;
	string ans;
	ans.push_back(y + '0');
	k=k%z;
	ans+=solve(k,n-1,y);
	return ans;
}

int main(){
	cout<<10*power(9,9)<<endl;
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<solve(n,10,11)<<endl;
	}
}
