#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'



#define nline '\n'
#define inf 1000000000
#define mod 1000000007
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462



#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve();

/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	int arr[n];
	rep(i, n) cin>>arr[i];

	int len = (1<<n);
	ll sum = 0;
	rep(i, n) sum += arr[i];

	ll min_diff = inf_ll;

	for (int i=0;i<len;i++)
	{
		ll set1 = 0;
		for (int j=0;j<n;j++)
		{
			if ( i & (1<<j))
				set1 += arr[j];
		}
		min_diff = min(min_diff, abs(sum-set1-set1));
	}

	cout<<min_diff;
}

