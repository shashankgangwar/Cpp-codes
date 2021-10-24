/*

You are given an array of N integers. Given that you have to pick a non-empty subsequence, 
what is the probability that you pick a subsequence which has the same value of bitwise and, or and xor?

Solution:

All the numbers in the chosen subsequence should be the same.

Why?

Say, if a= 1100, b=0110  chosen then xor= 1010 or=1110 and=0100, different.


say, if 1110,1110,1110 chosen, xor=1110,or=1110,and=1110

if  1110,1110,1110,1110 chosen, xor=0000,or=1110,and=1110

if, 0000,0000,0000 chosen, xor=0000,or=0000,and=0000

if, 0000,0000,0000,0000 chosen, xor=0000,or=0000,and=0000


Thus, if number chosen are zero then length of subsequence can be odd as well as even,

but if it is non-zero then length must be odd.


So, count the frequency of all elements.


say, cnt0,cnt1,cnt2,cnt3...

res=  (2^(cnt0-1) + 2^(cnt0-1) -1) + 2^(cnt1-1) +2^(cnt2-1)+.......

PS: nc1+nc3+nc5+nc7....= 2^(n-1)

    nc0+nc2+nc4+nc6+...= 2^(n-1)
*/

// adjust the solution according to constraints and modulous

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

ll solve(vector<int>& v){
	int n=v.size();
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++) mp[v[i]]++;
	ll ans=0;
	for(auto it : mp){
		int m= it.second;
		ans = (ll) ans + power(2,m-1);
		if(it.first==0) ans= (ll) ans + power(2,m-1) - 1;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<solve(v)<<endl;
}





































