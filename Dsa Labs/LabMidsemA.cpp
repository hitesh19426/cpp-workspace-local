#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define ull unsigned long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

bool check(vector<ull> &arr, ull mid, ull target){
	ull sum = 0;
	for(ull num : arr){
		if(num > mid)
			sum += num - mid;

		if(sum >= target)
			return true;
	}

	return false;
}

void solve(){
	int n;
	cin>>n;

	vector<ull> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	ull target;
	cin>>target;

	ull high = 0;
	for(int i=0; i<n; i++)
		high = max(high, arr[i]);

	ull low = 0, ans = 0;
	while(low <= high){
		ull mid = low + (high - low)/2;

		if(check(arr, mid, target)){
			ans = mid;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}

	cout << ans;

}
