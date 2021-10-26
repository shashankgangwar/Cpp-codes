
// Q: 1 (Tree Magic)

#include <bits/stdc++.h>
using namespace std;

vector<int> divs(1e6 + 5,-1);

void fill(){
	for(int i=2;i<=1e6;i+=2) divs[i] = 2;
	for(int i=3;i<=1e6;i+=2)
	{
		for(int j=i;j<=1e6;j+=i)
		{
			if(divs[j]==-1) divs[j] = i;
		}
	}
}

bool isPrime(int n)
{
	if(divs[n]==n && n!=1) return true;
	else return false;
}

int numFactor(int n)
{
	if(n==0) return 0;
	map<int,int>mp;
	while(n>1){
		mp[divs[n]]++;
		n /= divs[n];
	}

	int ans = 1;
	for(auto p : mp){
	    ans *= (1+p.second);
	}
	return ans;
}

int DFS(int i, vector<int> g[], vector<int> &primeXOR, vector<int>& val){
	int ans = 0;
	if(isPrime(val[i-1])) ans = ans^val[i-1];
	for(int v : g[i]){
		ans = ans ^ DFS(v,g,primeXOR,val);
	}
	primeXOR[i] = ans;
	return ans;
}

vector<int> solve(vector<int> parent, vector<int> val){
	fill();
	int n = val.size();
	vector<int> g[n+1];
	for(int i=0;i<n-1;i++){
		g[parent[i]].push_back(i+2);
	}
	
	vector<int> primeXOR(n+1);
	int tot = DFS(1,g,primeXOR,val);
	vector<int> answer;
	
	for(int i=0;i<n;i++){
	    answer.push_back(tot^primeXOR[i+1]);
	}
	
	for(int i=0;i<n;i++){
	    answer[i] = numFactor(answer[i]);
	}
	return answer;
}

int main()
{
	printf("Hello World\n");
	vector<int> ans = solve({2, 1,3,3},{7,6,4,1,3});
	for(int a : ans) cout<<a<<" ";
	return 0;
}
