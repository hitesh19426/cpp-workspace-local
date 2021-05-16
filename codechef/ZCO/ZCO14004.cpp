#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
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
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
using namespace std;
void solve();
int first_greater(int arr[], int n, int x, int l, int r);

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
		cout<<arr[0];
		return;
	}
	else if (n==2){
		cout<<arr[0]+arr[1];
		return;
	}

	ll dp[n];
	dp[0]=arr[0];
	dp[1]=arr[0]+arr[1];
	dp[2]=dp[1]+arr[2]-min(arr[2], min(arr[1], arr[0]));

	reps(i, 3, n){
		dp[i] = maxt(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i], dp[i-1]);
	}

	// rep(i, n){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;

	cout<<dp[n-1];
}

