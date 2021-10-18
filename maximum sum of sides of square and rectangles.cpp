/*

Given an array A where A[[i] defines the size of ith stick and another array F where F[i] defines the number of ith sticks present. Make squares and rectangles using
these sticks such that the sum of perimeter of all rectangles and squares formed is maximum. Return this maximum value.

*/

//Link: https://www.geeksforgeeks.org/maximum-of-sum-of-length-of-rectangles-and-squares-formed-by-given-sticks/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(vector<int>& A,vector<int>& F){
	int n=A.size();
	map<ll,ll> freq;
	for(int i=0;i<n;i++) freq[A[i]] += F[i];

	
	map<ll,ll> freq_2;

	for (auto i: freq)
	{
		if (freq[i.first] >= 2) freq_2[i.first] = freq[i.first];
	}

	
	vector<pair<ll,ll> > arr1;
	for (auto i:freq_2){
		arr1.push_back({i.first,(freq_2[(i.first)]/2)*2});
	}
		
	sort(arr1.begin(), arr1.end());
	reverse(arr1.begin(), arr1.end());
	
	ll sum = 0, x=0, temp=0;
	int i=0;
	n=arr1.size();
	for(auto i : arr1){
		sum+=((i.second/4)*4)*(i.first);
		temp+=(i.second%4)*(i.first);
		x+=i.second%4;
		if(x==4){
			x=0;
			sum+=temp;
			temp=0;
		}
	}
		

	cout << sum<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> A(n),F(n);
		for(int i=0;i<n;i++){
			cin>>A[i]>>F[i];
		}
		solve(A,F);
	}
	return 0;
}
