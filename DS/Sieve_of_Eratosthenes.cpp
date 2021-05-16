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
#define foreach(v) for (auto itr=v.begin();itr!=v.end();itr++)
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

/*Find vector of all primes <=n in sorted order*/
vi sieve_of_eratosthenes(int n)
{
	std::vector<bool> is_prime(n+1, true);
	std::vector<int> primes;
	is_prime[0] = is_prime[1] = false;

	/*You do not need to check for number after sqrt(n) since they will be 
	finalised already. It does not mean that there is no prime after i st i*i<=n. */
	for (int i=2;i*i<=n;i++)
	{
		if (is_prime[i])
		{
			for (int j=i*i;j<=n;j+=i)
			{
				is_prime[j]=false;
			}
		}
	}

	/*need to print all the prime numbers and not till sqrt(n)*/
	rep(i, n+1){
		if (is_prime[i]) 
			primes.push_back(i);
	}

	return primes;
}

void solve(){
	int n=30;

	vi primes = sieve_of_eratosthenes(n);

	foreach(primes)
		cout<<*itr<<" ";
	//cout<<endl;
}
