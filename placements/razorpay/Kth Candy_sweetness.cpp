
/* 

An array of candies is given that represents the sweetness of ith candy. A query of type i,x,k means update the sweetness of ith 
candy to x and display the Kth least sweet candy.

Link: https://www.hackerearth.com/problem/algorithm/kth-candy-1b6c0c6b-63aa7394/

*/



#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)

int A[100005], gr[100005];

int get(int x){
	
    int ans = 0;
    
    while (x > 0){
    	
        ans = ans + gr[x];
        x = x - (x & (-x));
        
    }
    return ans;
}

int change(int mid, int k){
	
    int tmp = get(mid);
    
    if (tmp >= k) return 1;
    
    return 0;
}

void update(int x, int val){
	
    while (x <= 100005) {
    	
        gr[x] = gr[x] + val;
        x = x + (x & (-x));
    }
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	
	f(i,0,n){
		cin>>A[i];
		update(A[i], 1);
	}
	
	int q,r;
	cin>>q>>r;
	vector<vector<int> > Q;
	
	f(i,0,q){
		int j,x,k;
		cin>>j>>x>>k;
		j--;
        update(A[j], -1);
        update(x, 1);
        A[j] = x;
        int low = 1, high = 100005, mid;
        
        while (high > low) {
            int mid = (low+high)/2;
            
            if (change(mid, k)) high = mid;
            
            else low = mid+1;
        }
        
        cout << low << " ";
	}
	cout << endl;
}
