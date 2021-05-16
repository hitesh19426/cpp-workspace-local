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
	int n, k;
	cin>>n>>k;

	int arr[n];
	rep(i, n) cin>>arr[i];

	sort(arr, arr+n);
	// cout<<n<<" "<<k<<endl;
	//rep(i, n){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	ll count=0;
	rep(i, n-1){
		if (k-arr[i]<=arr[i])
			break;

		int ind = first_greater(arr, n, k-arr[i], 0, n-1);
		//cout<<arr[i]<<" "<<ind<<endl;
		count += (ll)ind-i;
		//cout<<count<<endl;
	}

	cout<<count;

}


// sort(arr, arr+n);
// int ind=first_greater(arr, n, x, 0, n);
// if (ind==n)
// 	not possible;
// works correctly -- tested in ZCO15002 codechef
int first_greater(int arr[], int n, int x, int l, int r)
{
	if (r<l)
		return r;

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
