#include<bits/stdc++.h>
using namespace std;

int event_num;
unordered_set<string> st;
unordered_map<string,vector<int> > user_day_to_events;
vector<vector<string> > event_to_users;
vector<pair<int,int> > event_to_duration;

bool isLeap(int year){
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{   
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;

    if (m == 2){
        if (isLeap(y)) return (d <= 29);
        else return (d <= 28);
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return (d <= 30);
 	return true;
}
 
bool is_seperate(vector<int>& v, int s, int e){
	int n=v.size();
	for(int i=0;i<n;i++){
		int start=event_to_duration[v[i]].first;
		int end =event_to_duration[v[i]].second;
		if(s<end && e>start) return false;
	}
	return true;
}

bool is_valid_date(string& s){
	if(s.size()!=10) return false;
	for(int i=0;i<10;i++){
		if((i==4 || i==7) && s[i]!='-') return false;
		else if(i!=4 && i!=7){
			if(s[i]<'0' || s[i]>'9') return false;
		}
	}
	int d=stoi(s.substr(8,2));
	int m=stoi(s.substr(5,2));
	int y=stoi(s.substr(0,4));
	return isValidDate(d,m,y);
}

bool is_valid_num(string& s){	
	int n=s.size();
	if(n>4) return false;
	for(int i=0;i<n;i++){
		if(s[i]<'0' || s[i]>'9') return false;
	}
	return true;
}

void add(){
	string u;
	cin>>u;
	if(st.find(u)!=st.end()){
		cout<<"failure"<<endl;
		return;
	}
	st.insert(u);
	cout<<"success"<<endl;
	return;
}

void create(){
	string day,s,dur;
	int num;
	int start,end;
	cin>>day>>s>>dur>>num;
	
	vector<string> users(num);
	
	for(int i=0;i<num;i++){
		cin>>users[i];
		if(st.find(users[i])==st.end()){
			cout<<"failure"<<endl;
			return;
		}
	}
	
	if(is_valid_date(day) && is_valid_num(s) && is_valid_num(dur)){
		start=stoi(s);
		end=start + stoi(dur);
	}
	else{
		cout<<"failure"<<endl;
		return;
	}
	if(end>1440){
		cout<<"failure"<<endl;
		return;
	}
	
	for(int i=0;i<num;i++){
		string key= users[i] + day;
		if(user_day_to_events.find(key)==user_day_to_events.end()) continue;
		else{
			if(is_seperate(user_day_to_events[key],start,end)) continue;
			else{
				cout<<"failure"<<endl;
				return;
			}
		}
	}
	
	for(int i=0;i<num;i++){
		string key= users[i] + day;
		user_day_to_events[key].push_back(event_num);
	}	
	event_to_duration.push_back({start,end});
	event_to_users.push_back(users);
	event_num++;
	cout<<"success"<<endl;
	return;
}

void show(){
	string day,user;
	cin>>day>>user;
	string key = user + day;
	if(user_day_to_events.find(key)==user_day_to_events.end()){
		cout<<"none"<<endl;
		return;
	}
	int n= user_day_to_events[key].size();
	for(int i=0;i<n;i++){
		int ev = user_day_to_events[key][i];
		cout<<event_to_duration[ev].first<<"-"<<event_to_duration[ev].second<<" ";
		int m=event_to_users[ev].size();
		for(int j=0;j<m;j++){
			cout<<event_to_users[ev][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
void suggest(){
	string day;
	int start_s,start_e,dur,num;
	cin>>day>>start_s>>start_e>>dur>>num;
	if(start_s+dur>1440){
		cout<<"none"<<endl;
		return;
	}
	vector<string> users(num);
	for(int i=0;i<num;i++){
		cin>>users[i];
	}
	vector<int> v(1441,0);
	for(int i=0;i<num;i++){
		string key= users[i] + day;
		if(user_day_to_events.find(key)==user_day_to_events.end()) continue;
		int n=user_day_to_events[key].size();
		for(int j=0;j<n;j++){
			int ev=user_day_to_events[key][j];
			int s =event_to_duration[ev].first;
			int e =event_to_duration[ev].second;
			v[s]++;
			v[e]--;
		}
	}
	for(int i=1;i<1441;i++) v[i]+=v[i-1];
	int ans=0,k=0;
	for(int i=start_s;i+dur<=start_e;i++){
		if(v[i]==0){
			ans=i;
			k=0;
			while(i<1441 && v[i]==0){
				k++;
				i++;
			}
			if(k>=dur && ans+dur<=start_e){
				cout<<ans<<endl;
				return;
			}
		}
	}
	cout<<"none"<<endl;
}


int main(){
	int t;
	cin>>t;
	event_num=0;
	while(t--){
		string op;
		cin>>op;
		if(op[0]=='a') add();
		else if(op[0]=='c') create();
		else if(op[0]=='s' && op[1]=='h') show();
		else if(op[0]=='s' && op[1]=='u') suggest();
	}
	return 0;
}
