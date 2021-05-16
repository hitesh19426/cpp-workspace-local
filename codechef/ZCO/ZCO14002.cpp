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

	if (n<=2){
		cout<<0;
		return;
	}

	int dp[n];
	dp[0]=0, dp[1]=0, dp[2]=min(arr[0], min(arr[1], arr[2]));
	reps(i, 3, n){
		dp[i] = min(arr[i]+dp[i-1], min(arr[i-1]+dp[i-2], arr[i-2]+dp[i-3]));
	}

	cout<<dp[n-1];
}


// sort(arr, arr+n);
// int ind=first_greater(arr, n, x, 0, n);
// if (ind==n)
// 	not possible;
// works correctly -- tested in ZCO15002 codechef
int first_greater(int arr[], int n, int x, int l, int r)
{
	if (r<l)
		return n;

	int mid = (l+r)/2;
	int ans=n;
	if (arr[mid] < x){
		ans = first_greater(arr, n, x, mid+1, r);
	}
	else{
		ans = mid;
		ans = min(ans, first_greater(arr, n, x, l, mid-1));
	}
	return ans;
}
