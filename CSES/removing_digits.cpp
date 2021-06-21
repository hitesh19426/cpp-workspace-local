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
	int n;
	cin>>n;

	long long dp[n+1];
	fill(dp, dp+n+1, INT_MAX);
	dp[0] = 0;

	for(int i=1; i<=n; i++){
		bool digits[10]={false};
		int num = i;
		while(num)
			digits[num%10] = true, num/=10;

		for(int j=1; j<=9; j++)
			if(digits[j] && i-j>=0)
				dp[i] = min(dp[i], dp[i-j]+1);
	}

	cout<<dp[n];
}
