/*
Given n numbers of students in a classroom each having a couple of pencils, 
you are to find out how many pencil mountains you can make by collecting all the pencils in the classroom.
Assume One pencil is a singular unit and cannot be broken into multiple pieces.

eg n=3 ans=5

Solution: find nth catalan number,
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=0;
    for(int i=1;i<=n;i++){
        dp[n]+=solve(i-1,dp)*solve(n-i,dp);
    }
    return dp[n];
}

int catalan_number(int n) {
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
	cout<<catalan_number(3)<<" ";
}
