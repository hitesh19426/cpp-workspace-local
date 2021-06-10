#include <bits/stdc++.h>
using namespace std;
void solve();

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

bool check(vector<long long>& arr, long long mid, int k){
	int n = arr.size(), count = 0;
	long long sum = 0;
	for( int i=0; i<n; )
	{
		if(arr[i]>mid || count>k)
			return false;
		
		while(arr[i]+sum<=mid){
			sum += arr[i]; i++;
		}
		sum=0, count++;
	}
	return true;
}

// find all subarrays segemnt of len k
// find max in all those segments
// pick minimum from above.
// min (max)
// FFFF TTTTT

// max sum in subarray <=mid 
void solve(){
	int n, k;
	cin>>n>>k;

	vector<long long> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];

	long long l=1, r=100'000'000'000'000'000, ans=-1;
	while(l<=r){
		long long m=l+(r-l)/2;
		if(check(arr, m, k)){
			ans = m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	cout<<ans;
}
