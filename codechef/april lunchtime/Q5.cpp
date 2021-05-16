#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define inf_ll (ll)1e18
#define mod 1000000007
#define PI 3.141592653589793238462

#define pb push_back
#define mp make_pair
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) cout<< #x << " = " << x << endl;
#define printarr(i, arr, n)	for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

void solve();
vll sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
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

ll modulo(ll a, ll b) {
  ll c = a % b;
  return (c < 0) ? c + b : c ;
}

void solve(){
	int n, m, b;
	cin>>n>>m>>b;

	ll arr[n][m];
	rep(i, n) 
		rep(j, m) cin>>arr[i][j];

	ll dp[n+1][m+1];

	rep(i, n+1){
		rep(j, m+1){
			if (i==0 || j==0){
				dp[i][j]=0;
				continue;
			}
			dp[i][j] = arr[i-1][j-1];
		}
	}

	reps(i, 1, n+1){
		reps(j, 1, m+1){
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}

	ll ans = 0;

	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			{
				for (int l=k;l<=m;l++)
				{
					ll sum = dp[j][l]-dp[i-1][l]-dp[j][k-1]+dp[i-1][k-1];
					if (sum == b)
					{
						ans = (ans+1)%mod;
					}
				}
			}
		}
	}

	cout<<ans;
}
