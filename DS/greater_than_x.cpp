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
int first_greater(int arr[], int n, int x,  int l, int r);

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
	int arr[]={1, 2, 4, 5, 7, 9, 10, 13};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=5;


	sort(arr, arr+n);
	int ind=first_greater(arr, n, x, 0, n);
	cout<<ind<<" "<<arr[ind]<<endl;

}

// sort(arr, arr+n);
// int ind=first_greater(arr, n, x, 0, n);
// if (ind==n)
// 	not possible;
// works correctly -- tested in ZCO15002 codechef
// return index of first element >= x
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
