//Link : https://www.geeksforgeeks.org/program-nth-catalan-number/

/*
Program to find:
	
	1. nth catalan number;
	2. Count the number of expressions containing n pairs of parentheses which are correctly matched.
	3. Count the number of possible Binary Search Trees with n keys (See this)
	4. Count the number of full binary trees
	5. Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
	
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
	for(int i=0;i<10;i++) cout<<catalan_number(i)<<" ";
}
