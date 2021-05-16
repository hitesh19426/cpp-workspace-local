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
#define first_occurence(arr, n, x) lower_bound(arr, arr+n, x)
#define last_occurence(low, n, x) upper_bound(low, arr+n, x)
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

	sort(arr, arr+n);

	int dp[n];
	dp[0]=arr[0];
	reps(i, 1, n)	dp[i]=dp[i-1]+arr[i];

	ll sum=0;
	rep(i, n-1){
		sum += (ll)dp[n-1]-(ll)dp[i] - (ll)(n-i-1)*arr[i];
	}

	cout<<sum;
	
}