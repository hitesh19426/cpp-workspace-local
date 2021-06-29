#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

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

bool check(vector<int> &arr, int x, int mid){
	int sum=0, count=1;
	for(int i=0; i<(int)arr.size(); i++){
		if(arr[i]>mid)
			return false;
		if(sum+arr[i]<=mid){
			sum += arr[i];
			continue;
		}
		sum = arr[i];
		count++;
	}

	return count<=x;
}

void solve(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];

	int x;
	cin>>x;

	int l=0, r=1000'000'000, ans=-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(check(arr, x, mid))
			ans = mid, r=mid-1;
		else
			l=mid+1;
	}

	cout<<ans;
}
