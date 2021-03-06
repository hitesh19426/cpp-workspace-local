#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
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

	int len = (1<<n);
	for(int i=0; i<len; i++){
		int gi = i ^ (i>>1);

		for(int j=n-1; j>=0; j--){
			if(gi & (1<<j))
				cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
}

