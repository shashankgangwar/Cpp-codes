

//Q: 2 maximum work (hackerearth)
#include<bits/stdc++.h>
using namespace std;
 
int n;
int b;
int k;
int m;
vector<int> t;
vector<int> w;
bool ispossible(int x){
	if(n<x)return false;
	int i=0;
	int j=n-x;
	int cnt=0;
	
	while(i<m&&j<n){
		if(w[j]<t[i]){
			if((t[i]-w[j])%b==0) cnt+=(t[i]-w[j])/b;
			else cnt+=(t[i]-w[j])/b+1;
		}
		i++;
		j++;
	}  
	if(cnt<=k)return true;
	return false;
}
void solve(){
	cin>>k>>b>>n;
	w.resize(n);
	for(int i=0;i<n;i++)cin>>w[i];
	cin>>m;
	t.resize(m);
	for(int i=0;i<m;i++)cin>>t[i];
	
	sort(t.begin(),t.end());
	sort(w.begin(),w.end());
	
	int i=0;
	int j=m;
	int ans=0;
	while(i<=j){
	    int mid=(i+j)/2;
	    if(ispossible(mid)){
			ans=max(ans,mid);
    		i=mid+1;
	    }
	    else j=mid-1;
	}
	cout<<ans;
}

int main(){
solve();
}
