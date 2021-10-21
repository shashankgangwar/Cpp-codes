/*

you can perform k operation and in every operation, you can detach a leaf node and attach it to any other node.
then update the value of each node as the value of the sum of all the nodes in its subtree. Then find the 
value of tree. Value of tree is equal to sum of all the node. You have to minimize this tree value.

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<ll> degree,sum;
set<pair<int,int> > st;

void dfs(int i, vector<vector<int> >& A, int par, priority_queue<pair<int,int> >& pq, vector<int>& a){
	int cnt=0;
	for(int j: A[i]){
		if(j!=par){
			dfs(j,A,i,pq,a);
			cnt++;
		}
	}
	if(cnt==0){
		pq.push({a[i],i});
	}
	degree[i]=cnt+1;
}

ll dfs2(int i, vector<vector<int> >& A, int par, vector<int>& a){
	ll ans=a[i];
	for(int j:A[i]){
		if(j!=par && st.find({j,i})==st.end() && st.find({i,j})==st.end()){
			ans= (ll) ans + dfs2(j,A,i,a);
		}
	}
	sum[i]=ans;
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<vector<int> > A(n,vector<int>());
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		A[x-1].push_back(y-1);
		A[y-1].push_back(x-1);
	}
	
	degree=vector<ll>(n);
	sum=vector<ll>(n);
	st.clear();
	priority_queue<pair<int,int> > pq;
	dfs(0,A,-1,pq,a);
	
	while(k-- && pq.size()>0){
		int k=pq.top().second;
		pq.pop();
		int j=A[k][0];
		if(j==0) continue;
		st.insert({j,k});
		degree[j]--;
		A[0].push_back(k);
		if(degree[j]==1) pq.push({a[j],j});
	}
	
	dfs2(0,A,-1,a);
	
	ll ans=0;
	
	for(int i=0;i<n;i++){
		ans= (ll)ans + sum[i];
	}
	cout<<ans<<endl;
}

