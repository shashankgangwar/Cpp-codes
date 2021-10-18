/*
Partition an array into two non-empty subsets such that absolute difference between their sum is minimum
*/



#include<bits/stdc++.h>
using namespace std;
int solve(int arr[], int n, int sum, int i, int j, vector<vector<int> >& dp){
    if(i==n) return abs(sum-j);
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=min(solve(arr,n,sum-arr[i],i+1,j+arr[i],dp),solve(arr,n,sum,i+1,j,dp));
    return dp[i][j];
}
int minDifference(int arr[], int n)  { 
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    vector<vector<int> > dp(n+1,vector<int>(sum+1,-1));
    return solve(arr,n,sum,0,0,dp);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<minDifference(arr,n)<<endl;
	return 0;
}
