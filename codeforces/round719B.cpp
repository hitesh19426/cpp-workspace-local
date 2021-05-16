#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define mod 1000000007
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462

#define pb push_back
#define mp make_pair
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve();

/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	fastio();

	int t=1;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	std::vector<ll> v = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
	std::vector<ll> good;
	for (ll num:v)
	{
		for (ll i=1;i<=9;i++)
		{
			good.pb(i*num);
		}
	}

	// print(good);

	ll n;
	cin>>n;

	ll count=0;
	for (auto i:good)
	{
		if (i<=n)
			count++;
	}

	cout<<count;

}

