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

	long long factorial[1000002];
	factorial[0] = 1;
	for(int i=1; i<1000002; i++)
		factorial[i] = (i*factorial[i-1])%mod;

	int t=1;
	cin>>t;
	while(t--){
		int n, r;
		cin>>n>>r;

		long long x = factorial[n-r]*factorial[r] % mod;

		long long inverse = 1, b = mod-2;
		while(b>0){
			if(b&1)
				inverse = (inverse*x)%mod;
			x = (x*x)%mod;
			b >>= 1;
		}

		long long ans = (factorial[n] * inverse )%mod;
		cout<<ans;
		cout<<endl;
	}
	return 0;
}

/*Here is the explanation for above code:

nCr = n!/(n-r)!r!

nCr%p = n!/(n-r)!r! %p

		= n!*inverse((n-r)!r!) %p
		= n!%p * inverse((n-r)!r!)%p % p

we precompute all n!%p in factorial[] using n!%p = ( (n-1)!%p * n) % p

// inverse(x) = pow(x, p-2) for prime p

inverse((n-r)!r!) % p = pow((n-r)!r!, p-2) % p

							= pow(  (n-r)!r! %p, p-2 ) %p
							= pow(  factorial[n-r]*factorial[r]%p, p-2 )%p;

The second approach cannot be applied here since it takes O(mod) time and mod is 1e9+7

*/
