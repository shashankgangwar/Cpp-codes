/*
This is a method to calculate nCr of large numbers, when a lot of nCr values are to be calculated in question,
it calculates nCr in O(1) time, and requires preprocessing of O(n) TC.

if less values of nCr are needed to be calculated then we can go for direct calculations without preprocessing (second code)

*/


#include<iostream>
using namespace std;
#define ll long long int

ll k=100005;
ll fact[100006],inv[100006];
ll m=1000000007;

void calc_fact(){
	fact[0]=1;
	for (int i = 1; i<=k ; i++) {
		fact[i] = (fact[i-1]*i)%m;
	}
}

void calc_inv(){
	inv[0] = 1;
	inv[1] = 1;

	for (int i = 2; i <= k; i++) {
		inv[i] = m - (m / i) * inv[m % i]% m;
	}
	
	ll ans=1;
	
	for (int i = 2; i <= k; i++) {
		ans = (ans*inv[i])%m;
		inv[i]=ans;
	}
}

ll nCr(int n, int r){
	ll ans=fact[n];
	ans= (ans*inv[r])%m;
	ans= (ans*inv[n-r])%m;
	return ans;
}

int main(){
	calc_fact();
	calc_inv();
	for(int n=0;n<=1000;n++){
		ll ans=0;
		for(int s=0;s<=n;s++){
			for(int r=s;r<=n;r++){
				ans= (ans + (((s*s)%m)*(nCr(n,r)*nCr(r,s))%m)%m)%m;
			}
		}
		cout<<n<<" "<<ans<<endl;
	}
}




//if less values of nCr are needed to be calculated 


#include <bits/stdc++.h>
using namespace std;



int binomialCoeff(int n, int k)
{
	int res = 1;
	
	if (k > n - k) k = n - k;

	// Calculate value of
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

int main()
{
	int n = 8, k = 2;
	cout << "Value of C(" << n << ", "
		<< k << ") is " << binomialCoeff(n, k);
	return 0;
}




