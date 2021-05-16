#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n, k;
	cin>>n>>k;

	int arr[n];
	rep(i, n)	cin>>arr[i];

	int dp[n];
	if (arr[0]==1) 
		dp[0]=1;
	else dp[0]=0;
	for (int i=1;i<n;i++){
		if (arr[i]==1)
			dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	}

	int min_one=dp[k-1];
	for (int i=1;i<=n-k;i++){
		min_one = min(min_one, dp[i+k-1]-dp[i-1]);
	}

	int total_one=dp[n-1];
	ll ans=((ll)min_one*(min_one+1))/2 + total_one-min_one;
	cout<<ans;
}