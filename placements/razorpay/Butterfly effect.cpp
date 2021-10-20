//link: https://www.hackerearth.com/problem/algorithm/butterfly-effect-4e5d6946/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int c=1000000007;
ll solve(int n, int k, int x, int i, int j, vector<vector<ll> >& dp){
	if(i==n) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=0;
	for(int p=1;p<=k;p++){
		if(p==j && j!=x) continue;
		else{
			dp[i][j]=(dp[i][j]+solve(n,k,x,i+1,p,dp))%c;
		}
	}
	return dp[i][j];

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,x;
		cin>>n>>k>>x;
		vector<vector<ll> > dp(n,vector<ll>(k+1,-1));
		cout<<solve(n,k,x,0,0,dp)<<endl;
	}
}
