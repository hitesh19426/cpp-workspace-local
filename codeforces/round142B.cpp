#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define inf 1000000000
#define inf_ll 1000000000000000000
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<int, int>
#define vll vector<long long>
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
using namespace std;


vi sieve_of_erasthones(int n)
{
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i=2;i*i<=n;i++)
	{
		if (is_prime[i])
		{
			for (int j=i*i ; j<=n ; j+=i)
			{
				is_prime[j] = false;
			}
		}
	}

	std::vector<int> v;
	rep(i, n+1){
		if (is_prime[i])
			v.pb(i);
	}

	return v;
}

bool search(ll arr[], int n, int l, int r, ll x)
{
	if (r<l)
		return false;

	int m = l + (r-l)/2;
	if (arr[m]==x)
		return true;

	if (arr[m]<x)
		return search(arr, n, m+1, r, x);

	return search(arr, n, l, m-1, x);
}


int main(int argc, char const *argv[])
{
	/* code */
	vi primes=sieve_of_erasthones((int)pow(10, 6));
	int n=primes.size();

	ll squares[n];
	rep(i, n){
		squares[i] = (ll)primes[i]*primes[i];
	}

	// rep(i,n){
	// 	cout<<squares[i]<<" ";
	// }
	// cout<<endl;
	int t;
	cin>>t;

	while(t--){
	ll x;
	cin>>x;

	if (search(squares, n, 0, n-1, x))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	}
	return 0;
}
