//link: http://cplusplus.com/forum/beginner/247883/
//solution posted on the above link is wrong.

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A){
	int n=A.size();
	stack<pair<int,int> > st;
	int ans=0;
	for(int i=0;i<n;i++){
		int k=1;
		while(!st.empty() && st.top().first<=A[i]){
			ans=ans+st.top().second;
			if(st.top().first==A[i]) k+=st.top().second;
			st.pop();
		}
		if(!st.empty()) ans=ans+st.top().second;
		st.push({A[i],k});
	}
	return ans;
}
int main(){
	cout<<solve({2,3,2,1})<<endl;
	cout<<solve({3,2,1,3})<<endl;
	cout<<solve({1,1,1,1})<<endl;
	cout<<solve({3,1,1,1,12})<<endl;
}
