/* 

Maximum profit from different suppliers

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll sum(ll n){
	return n*(n+1)/2;
}

ll solve(int n, vector<ll>& A, ll order){
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	ll cnt=0;
	int i=0;
	ll ans=0;
	while(i<n && order>0){
		ll k=A[i];
		while(i<n && A[i]==k){
			i++; cnt++;	
		}
		if(i==n){
			ll x=order/cnt;
			ans=ans + (ll) cnt*(sum(k)-sum(k-x));
			ll y= order%cnt;
			ans = ans + y*(k-x);
			order=0;
		}
		else{
			ll next=A[i];
			ll odr=cnt*(k-next);
			if(odr>order){
				ll x=order/cnt;
				ans=ans + (ll) cnt*(sum(k)-sum(k-x));
				ll y= order%cnt;
				ans = ans + y*(k-x);
				order=0;
			}
			else{
				ans=ans + (ll) cnt*(sum(k)-sum(next));
				order=order-odr;
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<ll> A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	ll order;
	cin>>order;
	cout<<solve(n,A,order)<<endl;
	return 0;
}

