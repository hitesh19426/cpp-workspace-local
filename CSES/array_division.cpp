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

bool check(vector<int>& arr, long long mid, int k){
	int n = arr.size(), count = 1;
	long long sum = 0;

	for(int i=0; i<n; i++)
	{
		if(arr[i]>mid)
			return false;
		
		if(arr[i]+sum<=mid){
			sum += arr[i];
			continue;
		}
		sum=arr[i], count++;
	}

	return count<=k;
}

// FFFFTTTTTT
void solve(){
	int n, k;
	cin>>n>>k;

	vector<int> arr(n);
	long long sum = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum += arr[i];
	}

	long long l=1, r=sum, ans=-1;
	while(l<=r){
		long long mid = l+(r-l)/2;
		if(check(arr, mid, k)){
			ans = mid, r=mid-1;
		}
		else{
			l=mid+1;
		}
	}

	cout<<ans;
}
