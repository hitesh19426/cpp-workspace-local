#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000'000'007
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

pair<long long, long long> fibonacci(long long n)
{
	if(n==0)
		return {0, 1};

	auto fib = fibonacci(n/2);
	long long a = fib.first;
	long long b = fib.second;

	long long c = (a%mod)*( (2*b- a)%mod );
	long long d = (a*a)%mod + (b*b)%mod;
	c = (c%mod + mod)%mod;
	d %= mod;
	if(n&1)
		return {d%mod, (c+d)%mod};
	return {c%mod, d%mod};
}

void solve(){
	long long n;
	cin>>n;

	cout<<fibonacci(n).first;
}
