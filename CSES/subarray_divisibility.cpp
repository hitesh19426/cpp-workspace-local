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
	int n;
	cin>>n;

	int arr[n], rem[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	fill(rem, rem+n, 0);
	long long sum = 0, count = 0;

	for(int i=0; i<n; i++){
		sum += arr[i];
		int cur = (sum%n+n)%n;
		count += rem[cur];
		rem[cur]++;
		if(cur==0)
			count++;
	}

	cout<<count;
}
