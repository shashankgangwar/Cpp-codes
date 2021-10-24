/*

given the cost of integers from 0 to 9 in an array. Find the larget number that you can make with amount K.

the question can also ask as largest size of string that can be formed.

*/

#include<bits/stdc++.h>
using namespace std;

string solve(vector<int>& A, int k){
	vector<pair<int,int> > v;
	for(int i=0;i<10;i++) v.push_back({A[i],i});
	sort(v.begin(),v.end());
	if(k<v[0].first) return "";
	int x=0;
	string ans;
	
	//remove this if block if question asks about largest string instead of number or question specifies that there can be leading zeros
	if(v[0].second==0){
		if(v[1].first>k) return "0";
		ans.push_back(v[1].second + '0');
		k=k-v[1].first;
	}
	
	int n=k/v[0].first;
	for(int i=0;i<n;i++) ans.push_back(v[0].second + '0');
	k=k%v[0].first;
	n=ans.size();
	for(int i=0;i<n;i++){
		for(int j=9;j>ans[i]-'0';j--){
			if(A[j]-A[ans[i]-'0']<=k){
				ans[i]= j + '0';
				k= k - (A[j]-A[ans[i]-'0']);
				break;
			}
			else{
				continue;
			}
		}
		if(k==0) break;
	}
	return ans;
}

int main(){
	vector<int> A(10);
	for(int i=0;i<=9;i++) cin>>A[i];
	int k;
	cin>>k;
	cout<<solve(A,k)<<endl;
}
