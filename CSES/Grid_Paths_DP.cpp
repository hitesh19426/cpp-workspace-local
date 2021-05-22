#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define nline "\n"

#define mod 1000000007

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

	string s[n];
	rep(i, n) cin>>s[i];

	int dp[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			if(s[i][j]=='*'){
				dp[i][j] = 0;
			}
			else if(i==0 && j==0){
				dp[i][j] = 1;
			}
			else if(i==0){
				dp[i][j] = dp[i][j-1]%mod;
			}
			else if(j==0){
				dp[i][j] = dp[i-1][j]%mod;
			}
			else{
				dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
			}
		}
	}

	cout<<dp[n-1][n-1];
}

