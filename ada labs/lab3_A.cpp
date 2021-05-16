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
ll find_ans(int arr[], int n, int l, int r, int k);
bool seq_of_k(int arr[], int n, int k, int min_diff);

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
	rep(i, n)	cin>>arr[i];

	sort(arr, arr+n);

	ll ans=find_ans(arr, n, 0, arr[n-1], k);
	cout<<ans;
}

ll find_ans(int arr[], int n, int l, int r, int k){
	if (r<l){
		return 0;
	}

	int mid=l+(r-l)/2;
	ll ans=0;

	if (seq_of_k(arr, n, k, mid)){
		ans = mid;
		ans = max(ans, find_ans(arr, n, mid+1, r, k));
	}
	else{
		ans = max(ans,find_ans(arr, n, l, mid-1, k));
	}

	return ans;
}

bool seq_of_k(int arr[], int n, int k, int min_diff){
	int len=1;
	int last=arr[0];

	reps(i, 1, n){
		if (abs(last-arr[i])>=min_diff){
			last=arr[i];
			len++;
		}
		if (len==k)
			return true;
	}
	return false;
}