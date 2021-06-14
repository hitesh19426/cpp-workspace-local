#include <bits/stdc++.h>
using namespace std;
void solve();

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*----------------------------------------------------------------------------------------------------*/

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

	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	set<int> ans;
	for(int i=0; i<n; i++){
		vector<int> v(ans.begin(), ans.end());
		for(int x:v){
			ans.insert(x+arr[i]);
		}
		ans.insert(arr[i]);
	}

	cout<<ans.size()<<endl;
	for(int i:ans){
		cout<<i<<" ";
	}
}
