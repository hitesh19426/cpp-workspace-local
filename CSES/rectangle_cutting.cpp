#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
	int a, b;
	cin>>a>>b;

	// int dp[a][b];
	vector<vector<long long>> dp(a, vector<long long>(b, INT_MAX));

	for(int i=1; i<=a; i++){
		for(int j=1; j<=b; j++){
			if(i==j){
				dp[i-1][j-1] = 0;
				continue;
			}
		
			for(int x=1; x<i; x++)
				dp[i-1][j-1] = min(dp[i-1][j-1], dp[i-x-1][j-1] + dp[x-1][j-1] + 1);
			for(int y=1; y<j; y++)
				dp[i-1][j-1] = min(dp[i-1][j-1], dp[i-1][j-y-1] + dp[i-1][y-1] + 1);	
		}
	}

	cout<<dp[a-1][b-1];
}
