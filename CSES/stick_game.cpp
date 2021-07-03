#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
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

void solve(){
	int n, k;
	cin>>n>>k;

	int arr[k];
	for(int i=0; i<k; i++) cin>>arr[i];
	sort(arr, arr+k);

	string ans = "WW";

	for(int i=2; i<=n; i++){
		bool found = false;

		for(int j=0; j<k; j++){
			if(arr[j]==i){
				ans += "W", found = true;
				break;
			}
			else if( i-arr[j] > 0 && ans[i-arr[j]] == 'L' ){
				ans += "W", found = true;
				break;
			}
		}

		if(!found){
			ans += "L";
		}
	}

	for(int i=1; i<(int)ans.size(); i++)
		cout<<ans[i];

}
