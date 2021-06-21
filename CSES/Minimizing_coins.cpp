#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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

	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	vector<long long> dp(x+1, INT_MAX);
	dp[0] = 0;

	for(int i=1; i<=x; i++)
		for(int j=0; j<n; j++)
			if(i-arr[j]>=0)
				dp[i] = min(dp[i], dp[i-arr[j]]+1);

	cout << (dp[x]==INT_MAX ? -1 : dp[x]);

}
