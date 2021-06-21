#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007

//----------------------------------------------------------------------------------------------------//

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
	int n, x;
	cin>>n>>x;

	int coins[n];
	for(int i=0; i<n; i++) cin>>coins[i];

	long long dp[x+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i=0; i<n; i++)
		for(int j=coins[i]; j<=x; j++)
			dp[j] += dp[j-coins[i]], dp[j] = dp[j]%mod;	
			// here dp[j] stores dp[i-1][j] from before

	cout<<dp[x];
}


// dp[i][j] = dp[i][j-1] + dp[i-coins[j]][j];
/*
If you iterate over j first, then dp[i-coins[j]][j] is a value filled in dp during that round only,
i, j-1 is nothing but the value that was stored in that dp earlier.
*/