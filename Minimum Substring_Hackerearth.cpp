/*

https://codeforces.com/gym/102881/problem/A

*/

#include<bits/stdc++.h>
using namespace std;
int solve(string& s, string& t)
{
	map<char, int> mp1;
	for (int i = 0; i < t.length(); i++) {
		mp1[t[i]]++;
	}
	map<char, vector<int> > mp2;
	for (int i = 0; i < s.length(); i++) {

		char x = s[i];
		if (mp1.find(x) != mp1.end()) {
			mp2[x].push_back(i);
		}
	}

	int ans = INT_MAX;
	int flag;
	while (true) {
		flag = 1;
		int a, b;

		for (int i = 0; i < t.length(); i++) {
			if (i == 0) {
				if (mp2.find(t[i]) == mp2.end()) {
					flag = 0;
					break;
				}
				else {
					int x = *(mp2[t[i]].begin());
					mp2[t[i]].erase(mp2[t[i]].begin());
					if(mp2[t[i]].size()==0) mp2.erase(t[i]);
					a = x;
					b = x;
				}
			}
			else {

				int elementFound = 0;
				for (auto e : mp2[t[i]]) {
					if (e > b) {
						elementFound = 1;
						b = e;
						break;
					}
				}
				if (elementFound == 0) {
					flag = 0;
					break;
				}
			}
		}

		if (flag == 0) break;
		ans = min(ans,abs(b - a) + 1);
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string T="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		cout<<solve(s,T)<<endl;
	}
}

