#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

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


ll expo(int x, int n)
{
	if (n==0)
		return 1;
	if (n==1)
		return x;

	ll val = expo(x, n/2);
	if (n&1)
		return val*val*x;
	return val*val;
}

void solve()
{
	int n;
	cin>>n;

	int sum = 0;
	ll pow = 5;
	while (pow<=n){
		sum += n/(pow);
		pow *= 5;
	}

	cout<<sum;
}

