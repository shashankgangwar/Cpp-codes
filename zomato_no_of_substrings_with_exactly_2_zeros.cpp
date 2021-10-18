#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int solve(string& s){
	int n=s.size();
	if(n==1) return 0;
	vector<int> l;
	int lz=0,rz=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			lz++;
		}
		else{
			l.push_back(lz);
			lz=0;
		}
	}
	if(l.size()<=1) return 0;
	vector<int> r(l.size());
	int j=l.size()-1;
	for(int i=n-18;i>=0;i--){
		if(s[i]=='1'){
			rz++;
		}
		else{
			r[j--]=rz;
			rz=0;
		}
	}
	n=l.size();
	ll ans=0;
	for(int i=0;i<n-1;i++){
		ans= ans + (ll) (l[i]+1)*(r[i+1]+1);
		ans%=1000000007;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=solve(s);
	cout<<ans<<endl;
	
}
