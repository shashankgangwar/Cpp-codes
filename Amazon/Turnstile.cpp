/*
Link: https://leetcode.com/discuss/interview-question/699973/Goldman-Sachs-or-OA-or-Turnstile
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>& time, vector<int>& dir){
	
	int n=time.size();
	vector<int> ans(n);
	if(n==0) return ans;
	if(n==1) return {time[0]};
	queue<pair<int,int> > entry,exit;
	
	for(int i=0;i<n;i++){
		if(dir[i]==1) exit.push({time[i],i});
		else entry.push({time[i],i});
	}
	
	int prev=-1,t=-1;
	while(!entry.empty() && !exit.empty()){
		int en_t=entry.front().first;
		int in=entry.front().second;
		int ex_t=exit.front().first;
		int ix=exit.front().second;
		
		if(t+1>en_t) en_t=t+1;
		if(t+1>ex_t) ex_t=t+1;
		
		if(en_t==ex_t){
			if(prev==0){
				ans[in]=en_t;
				t=ans[in];
				entry.pop();
			}
			else{
				ans[ix]=ex_t;
				t=ans[ix];
				exit.pop();
				prev=1;
			}
		}
		else if(min(en_t,ex_t)==en_t){
			ans[in]=en_t;
			t=ans[in];
			entry.pop();
			prev=0;
		}
		else{
			ans[ix]=ex_t;
			t=ans[ix];
			exit.pop();
			prev=1;
		}
	}
	
	while(!entry.empty()){
		int en_t=entry.front().first;
		int in=entry.front().second;
		ans[in]=max(t+1,en_t);
		t=ans[in];
		entry.pop();
	}
	
	while(!exit.empty()){
		int en_t=exit.front().first;
		int in=exit.front().second;
		ans[in]=max(t+1,en_t);
		t=ans[in];
		exit.pop();
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> time(n);
		for(int i=0;i<n;i++) cin>>time[i];
		vector<int> dir(n);
		for(int i=0;i<n;i++) cin>>dir[i];
		vector<int> ans=solve(time,dir);
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
		
	return 0;
}
