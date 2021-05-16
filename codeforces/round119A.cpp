#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define inf 1000000000
#define inf_ll 1000000000000000000
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<int, int>
#define vll vector<long long>
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(s)	for (auto itr=s.begin();itr!=s.end();itr++)
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve()
{
	int n, a, b, c;
	cin>>n>>a>>b>>c;

	set<int> s = {a, b, c};
	std::vector<int> v;
	for (auto itr=s.begin();itr!=s.end();itr++){
		v.pb(*itr);
	}
	
	// foreach(v)
	// 	cout<<*itr<<" ";
	// cout<<endl;

	int arr[n+1];
	rep(i, n+1) arr[i]=0;

	foreach(v)
	{
		
		// cout<<arr[0]<<" ";
		for (int i=1;i<n+1;i++)
		{
			if (i==*itr){
				arr[i] = max(arr[i], 1);
				// cout<<arr[i]<<" ";
				continue;
			}
			if (i-*itr>=0 && arr[i-*itr])
			{
				arr[i] = max(arr[i], arr[i-*itr]+1);
			}

			//cout<<arr[i]<<" ";
		}
		// cout<<endl;
	}
	 
	cout<<arr[n]; 
	//cout<<ways(n, v);
}
