#include<bits/stdc++.h>
using namespace std;
 
void color(vector<pair<int,int> > &tree,int c,int v,int n){
	if(2*v<=n){
		tree[2*v].second=c;
	}
	if(2*v+1<=n){
		tree[2*v+1].second=c;
	}
 
	if(2*v+1>n){
		return;
	}
	else{
		color(tree,c,2*v,n);
		color(tree,c,2*v+1,n);
	}
}
 
vector<int> ColoringTree(int N,int Q,vector<vector<int> >queries){
	vector<int>result;
	vector<pair<int,int> >tree;
	tree.push_back({0,0});
	int i;
	for(i=1;i<=N;i++){
		tree.push_back({i+1,0});
	}
	int cnt=1;
	int m=queries.size();
	for(i=0;i<m;i++){
		if(queries[i][0]==1){
			int v=queries[i][1];
			result.push_back(tree[v].second);
		}
		else{
			int v=queries[i][1];
			color(tree,cnt,v,N);
			cnt++;
		}
	}
 
	return result;
}
