#include <bits/stdc++.h>
using namespace std;
void solve();

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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
	int n, x;
	cin>>n>>x;
 
	int prices[n];
	for(int i=0;i<n;i++) cin>>prices[i];
 
	int pages[n];
	for(int i=0;i<n;i++) cin>>pages[i];
 
	int dp[n+1][x+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if( j-prices[i-1] >= 0)
			{
				dp[i][j] = max( dp[i-1][j], pages[i-1] + dp[i-1][j-prices[i-1]] );
			}
			else{
				dp[i][j] = dp[i-1][j] ;
			}
		}	
	}
	cout << dp[n][x];
}

