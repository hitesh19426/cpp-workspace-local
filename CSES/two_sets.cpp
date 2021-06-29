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
	int n;
	cin>>n;

	int sum = (n*(n+1))/2;
	if(sum&1){
		cout<<0;
		return;
	}
	sum /=2;

	long long dp[n][sum+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for(int i=1; i<n; i++){
		for(int j=0; j<=sum; j++){
			dp[i][j] += dp[i-1][j] + (j-i-1>=0 ? dp[i-1][j-i-1] : 0);
			dp[i][j] %= mod;
		}
	}

	cout<<dp[n-1][sum];
}
