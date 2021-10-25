/*

Given an array A. Count of all subarrays whose sum of divisors of elements in that subarray is odd. 1 and the number itself are considered divisors in this question

steps: 
	1. make an array that stores the sum of divisors of ith element
	2. find the number of subarrays with odd sum in this array
Time Complexity: O(n*(max_number)^0.5)
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int subarrays_with_odd_sum(vector<ll>& v){
	int temp[2] = { 1, 0 };
	ll ans = 0, val = 0;
	int n=v.size();

	for (int i = 0; i < n ; i++) {
		val = (((ll)val + v[i]) % 2 + 2) % 2;
		temp[val]++;
	}

	ans = (temp[0] * temp[1]);

	return ans;
}

ll divisor_sum(int n){
	ll ans=0; 
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			ans= (ll) ans + i;
			if(i*i!=n) ans= (ll) ans + n/i;
		}
	}
	return ans;
}

int solve(vector<int>& A){
	int n=A.size();
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		v[i]=divisor_sum(A[i]);
	}
	cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
	return subarrays_with_odd_sum(v);
}
int main()
{
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<solve(A)<<endl;
	return 0;
}

