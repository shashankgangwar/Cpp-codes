
// solution 1; failed for two test cases


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


// solution 2

#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin>>n;
    set<string> users;
    map<pair<string,string>,vector<int>> m;
    while(n--)
    {
        string s;
        getline(cin,s);
        int x=s.length();
        if(x==0)
        {
            n++;
            continue;
        }
        if(s[0]=='a')
        {
            int c=0;
            for(int i=0;i<x;i++)
            {
                if(s[i]=='r')
                {
                    c=i+2;
                    break;
                }
            }
            string t="";
            for(int i=c;i<x;i++)
            {
                t+=s[i];
            }
            if(users.count(t))
            {
                cout<<"failure"<<endl;
            }
            else
            {
                users.insert(t);
                cout<<"success"<<endl;
            }
        }
        else if(s[0]=='c')
        {
            int c=0;
            string date="";
            for(int i=0;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                date+=s[i];
            }
            int l=0,r=0,num=0;
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                l=l*10+(ch-48);
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                r=r*10+(ch-48);
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                num=num*10+(ch-48);
            }
            set<string> u;
            while(num--)
            {
                string t="";
                for(int i=c;i<x;i++)
                {
                    if(s[i]==' ')
                    {
                        c=i+1;
                        break;
                    }
                    t+=s[i];
                }
                u.insert(t);
            }
            if((l+r)>=1440)
            {
                cout<<"failure"<<endl;
                continue;
            }
            int f=0;
            for(auto it: u)
            {
                if(m[make_pair(date,it)].size()==0)
                {
                    for(int i=0;i<1440;i++)
                    {
                        m[make_pair(date,it)].push_back(0);
                    }
                }
                else
                {
                    for(int i=l;i<(l+r);i++)
                    {
                        if(m[make_pair(date,it)][i]==1)
                        {
                            f=1;
                            break;
                        }
                    }
                }
                if(f==1)
                    break;
            }
            if(f)
            {
                cout<<"failure"<<endl;
            }
            else
            {
                for(auto it: u)
                {
                    for(int i=l;i<(l+r);i++)
                    {
                        m[make_pair(date,it)][i]=1;
                    }
                }
                cout<<"success"<<endl;
            }
        }
        else if(s[0]=='sh')
        {
            int c=0;
            string date="",user="";
            for(int i=0;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                date+=s[i];
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                user+=s[i];
            }
            vector<pair,int,int>> p;
            if(m[make_pair(date,user)].size()==0)
            {
                continue;
            }
            int last=0,temp=-1;
            for(int i=0;i<1440;i++)
            {
                if(m[make_pair(date,user)][i]==1)
                {
                    if(temp==-1)
                    {
                        last=i;
                        temp=1;
                    }
                    else
                    {
                        temp++;
                    }
                }
                else if(temp>0)
                {
                    p.push_back(make_pair(last,temp));
                    temp=-1;
                }
            }
            if(temp>0)
            {
                p.push_back(make_pair(last,temp));
            }
            for(int i=0;i<p.size();i++)
            {
                set<string> u;
                for(auto it: users)
                {
                    if(m[make_pair(date,it)][p[i].first]==1)
                    {
                        u.insert(it);
                    }
                }
                cout<<p[i].first<<"-"<<p[i].first+p[i].second<<" ";
                for(auto it: u)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            int c=0;
            string date="";
            for(int i=0;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                date+=s[i];
            }
            int l=0,r=0,time=0,num=0;
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                l=l*10+(ch-48);
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                r=r*10+(ch-48);
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                time=time*10+(ch-48);
            }
            for(int i=c;i<x;i++)
            {
                if(s[i]==' ')
                {
                    c=i+1;
                    break;
                }
                char ch=s[i];
                num=num*10+(ch-48);
            }
            set<string> u;
            while(num--)
            {
                string t="";
                for(int i=c;i<x;i++)
                {
                    if(s[i]==' ')
                    {
                        c=i+1;
                        break;
                    }
                    t+=s[i];
                }
                u.insert(t);
            }
            for(int i=l;(i+time)<=r;i++)
            {
                int f=0;
                for(int j=i;j<(j+time);j++)
                {
                    for(auto it: u)
                    {
                        if(m[make_pair(date,it)][j]==1)
                        {
                            f=1;
                            break;
                        }
                    }
                    if(f==1)
                        break;
                }
                if(f==0)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
