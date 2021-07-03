#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
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
	long long a, b, c;
	cin>>a>>b>>c;

	long long res = 1;
	while(c>0){
		if(c&1)
			res = (res*b)%(mod-1);
		b = (b*b)%(mod-1);
		c >>= 1;
	}

	long long n = res, ans = 1;
	if(n==0 && a==0){
		cout<<1;
		return;
	}

	while(n>0){
		if(n&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		n >>= 1;
	}

	cout<<ans;
}

