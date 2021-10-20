/*

Given an integer n, find the nth number among the sequence of numbers of the form 2^p*3^q*5*r

Link: https://www.geeksforgeeks.org/ugly-numbers/

Can be done in O(nlogn) using set or priority queue;

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll nthUglyNumber(int n)
{
	if (n == 1 or n == 2 or n == 3 or n == 4 or n == 5)
		return n;

	set<long long int> s;
	s.insert(1);
	n--;

	while (n) {
		auto it = s.begin();

		long long int x = *it;
		s.erase(it);
		s.insert((ll)x * 2);
		s.insert((ll)x * 3);
		s.insert((ll)x * 5);
		n--;
	}

	return *s.begin();
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout << nthUglyNumber(n)<<endl;
	}
	
}


/* 

O(log N): can be used if nth number is in a known range:
	n>1000: value will cross INT_MAX;
	n>10000: value will cross long long int;
	use this method only if it specially demands to solve in O(log N)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll nthUglyNumber(int n)
{

	ll pow[40] = { 1 };
	
	for (int i = 1; i <= 62; ++i)
		pow[i] = (ll)pow[i - 1] * 2;
	
	ll l = 1, r = INT_MAX; //nth number will lie in this range;
	
	ll ans = -1;
	
	while (l <= r) {
	
		ll mid = l + (r - l) / 2;

		ll cnt = 0;
	
		for (ll i = 1; i <= mid; i *= 5)
	
		{
			for (ll j = 1; j * i <= mid; j *= 3)
		
			{
				cnt += upper_bound(pow, pow + 31, mid / (i * j)) - pow;
			}
		}
		if (cnt < n) l = mid + 1;
		else r = mid - 1, ans = mid;
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
		cout << nthUglyNumber(n)<<endl;
	}
	return 0;
}

