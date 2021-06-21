#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

class project
{
public:
	int start, end, reward;
};

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

void solve(){
	int n;
	cin>>n;

	project arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i].start>>arr[i].end>>arr[i].reward;
	}

	sort(arr, arr + n, [](project &a, project &b) -> bool {
		return a.end < b.end;
	});

	long long dp[n];
	dp[0] = arr[0].reward;
	
	for(int i=1; i<n; i++)
	{
		int low=0, high=i-1, ind=-1;
		while(low<=high){
			int mid = low+(high-low)/2;
			if(arr[mid].end<arr[i].start)
				ind = mid, low = mid+1;
			else
				high = mid-1;
		}

		if(ind == -1)
			dp[i] = arr[i].reward;
		else
			dp[i] = max(dp[i-1], arr[i].reward + dp[ind]);
		dp[i] = max(dp[i-1], dp[i]);	// only neccessary if end time of two intervals can be same
	}

	cout<<dp[n-1];
}
