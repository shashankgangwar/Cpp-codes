/*
Mud Walls

Link: https://github.com/QinmengLUAN/Daily_Python_Coding/blob/master/HankerRank_maxHeight_Math.py

*/

#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& p, vector<int>& h){
	int n=h.size();
	if(n==1) return 0;
	int ans=INT_MIN;
	for(int i=0;i<n-1;i++){
		int minh=min(h[i],h[i+1]);
		int diff=abs(h[i]-h[i+1]);
		int pos=p[i+1]-p[i]-1;
		if(pos<=diff){
			ans=max(ans,minh+pos);
		}
		else{
			int rem_pos=pos-diff;
			int max_h=minh+diff+rem_pos/2+rem_pos%2;
			ans=max(ans,max_h);
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	vector<int> h(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	cout<<solve(p,h);
		return 0;
}
