//link: https://code.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/katrina-and-library-c2ed51f3/

#include<bits/stdc++.h>
using namespace std;
string solve(string& s){
	int n=s.size();
	if(n==2) return "";
	stack<string> st;
	string temp;
	for(int i=0;i<n;i++){
		if(s[i]=='/'){
			if(temp.size()>0){
				st.push(temp);
				temp="";
			}
			st.push("/");
		}
		else if(s[i]==92){
			while(st.top()!="/"){
				temp=st.top()+temp;
				st.pop();
			}
			st.pop();
			reverse(temp.begin(),temp.end());
			st.push(temp);
			temp="";
		}
		else{
			temp.push_back(s[i]);
		}
	}
	return st.top();
}
int main(){
	string s;
	cin>>s;
	string ans=solve(s);
	cout<<ans<<endl;
	return 0;
}
