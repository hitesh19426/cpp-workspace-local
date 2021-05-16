#include<bits/stdc++.h>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define endl '\n'
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	int arr[n];
	rep(i, n)	cin>>arr[i];

	if (n==1){
		cout<<0;
		return;
	}

	sort(arr, arr+n);
	// rep(i, n){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	ll dp[n][n];
	rep(i, n){
		rep(j, n) dp[i][j]=0;
	}

	


	for (int i=1;i<n;i++)
	{
		for (int x=0, y=i; x<n && y<n; x++, y++)
		{
			dp[x][y] = arr[y] - arr[x] + min(dp[x+1][y], dp[x][y-1]);
		}
	}

	cout<<dp[0][n-1];

}

