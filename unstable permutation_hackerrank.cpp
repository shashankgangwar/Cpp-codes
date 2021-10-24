/*

Given an array A, find in how many operations we can make the array stable.
In one operation we have to pu A[i]= A[A[i]];
An array becomes stable if it cannot be changed by applying further operations.

Link: https://codeforces.com/blog/entry/83400

*/



#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& A){
	int n=A.size();
	vector<int> vis(n+1,0);
	int cs=0,max_cs=0;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			int j=i;
			cs=0;
			while(vis[j]==0){
				cs++;
				vis[j]=1;
				j=A[j]-1;
			}
			int k=log2(cs);
			if(pow(2,k)!=cs) return -1;
			else max_cs=max(max_cs,cs);
		}
	}
	return log2(max_cs);
}

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	cout<<solve(A)<<endl;
}
