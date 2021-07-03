#include <bits/stdc++.h>
using namespace std;

void solve();
#define endl '\n'
const int mod = 1e9 + 7;
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
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	long long a, b;
	cin>>a>>b;

	if(b==0){
		cout<<1;
		return ;
	}

	long long res = 1;
	while(b>0){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;	// b/= 2;
	}

	cout<<res;
}

