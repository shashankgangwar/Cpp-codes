#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<vector<int> > > mp1;
unordered_map<string,unordered_set<int> > mp2;
void add(string& sc, vector<int>& v){
	
	int nr,npr;
	nr=v[0];
	npr=v[1];
	
	if(mp1.find(sc)!=mp1.end()){
		cout<<"failure"<<endl;
		return;
	}
	else{
		mp1[sc]=vector<vector<int> >(nr+1,vector<int>(npr+1,0));
		unordered_set<int> st;
		int n=v.size();
		for(int i=2;i<n;i++) st.insert(v[i]);
		mp2[sc]=st;
	}
	cout<<"success"<<endl;
	return;
}

void reserve(string& sc, vector<int>& v){
	int rn=v[0];
	int n=v.size();
	
	if(mp1.find(sc)==mp1.end() || mp1[sc].size()<=rn || rn<=0){
		cout<<"failure"<<endl;
		return;
	}
	
	for(int i=1;i<n;i++){
		if(mp1[sc][rn].size()<=v[i] || v[i]<=0 || mp1[sc][rn][v[i]]==1){
			cout<<"failure"<<endl;
			return;
		}
	}
	for(int i=1;i<n;i++){
		if(mp1[sc][rn][v[i]]==1){
			cout<<"failure"<<endl;
			for(;i>=1;i--){
				mp1[sc][rn][v[i]]=0;
			}
			return;
		}
		mp1[sc][rn][v[i]]=1;
	}
	cout<<"success"<<endl;
	return;
}

void get(string& sc, vector<int>& v){
	int n=v.size();
	int rn=v[0];
	int m=mp1[sc][rn].size();
	for(int i=1;i<m;i++){
		if(mp1[sc][rn][i]==0) cout<<i<<" ";
	}
	cout<<endl;
}

void suggest(string& sc, vector<int>& v){
	int n=v.size();
	int ns=v[0],rn=v[1],c=v[2];
	
	
	
	if(mp1.find(sc)==mp1.end() || mp1[sc].size()<=rn || rn<=0){
		cout<<"none"<<endl;
		return;
	}
	
	int k=0, m = mp1[sc][rn].size();
	
	for(int i=c;i>=1;i--){
		if(mp1[sc][rn][i]==0) k++;
		else break;
		if(mp2[sc].find(i)!=mp2[sc].end() && mp2[sc].find(i-1)!=mp2[sc].end()) break;
		
	}
	
	if(k>=ns){
		while(ns--){
			cout<<c-ns<<" ";
		}
		cout<<endl;
		return;
	}
	
	k=0;
	for(int i=c;i<m;i++){
		if(mp1[sc][rn][i]==0) k++;
		else break;
		if(mp2[sc].find(i)!=mp2[sc].end() && mp2[sc].find(i+1)!=mp2[sc].end()) break;
	}
	
	if(k>=ns){
		while(ns--){
			cout<<c<<" ";
			c++;
		}
		cout<<endl;
		return;
	}
	
	cout<<"none"<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		
		string op,sc,A;
		cin>>op;
		cin>>sc;
		getline(cin,A);
		
		vector<int> v;
		int n=A.size(),temp=0;
		int i=0;
		while(A[i]==' ' && i<n) i++;
		while(A.size()>0 && A.back()==' ') A.pop_back();
		n=A.size();
		for(;i<n;i++){
			if(A[i]==' '){
				v.push_back(temp);
				temp=0;
			}
			else{
				temp= temp*10 + (A[i]-'0');
			}
		}
		v.push_back(temp);

		if(op[0]=='a') add(sc,v);
		else if(op[0]=='g') get(sc,v);
		else if(op[0]=='r') reserve(sc,v);
		else if(op[0]=='s') suggest(sc,v);
	}
	return 0;
}


