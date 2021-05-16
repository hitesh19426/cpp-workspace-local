#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

#define pb push_back
#define mp make_pair
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve();

#ifndef ONLINE_JUDGE
#define print(x) cerr<< #x << " = "; _print(x); cerr<<endl;
#else
#define print(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

/*----------------------------------------------------------------------------------------------------*/
pair<vector<int>, vector<bool>> sieve(int n)
{
	vector<bool> is_prime(n+1, true);
	vector<int> primes;
	is_prime[0] = is_prime[1] = false;
	
	for (int i=2;i<=n;i++) 
	{
		if (is_prime[i])
		{
			primes.push_back(i);
			for (int j=i*i;j<=n;j+=i)
				is_prime[j]=false;
		}
	}

	return mp(primes, is_prime);
}


ll integer_multiples(int x, int b, vector<int> primes, vector<bool> is_prime)
{
	if (x==0)
		return (ll)b - 1;

	if (is_prime[x]){
		if (x<b)
			return 2;
		return 1;
	}

	if (x<b)
	{
		ll total  = 1;
		for (int i:primes)
		{
			int _count = 0;
			if (x%i == 0)
			{
				while (x%i==0){
					x /= i;
					_count++;
				}
				total *= (_count+1);

			}

		}

		return total;
	}

	ll count = 0;	
	for (int i=1; i*i<=x && i<b; i++)
	{
		if (x%i==0)
		{
			if (i == x/i){
				count++;
			}
			else
			{
				count++;
				if (x/i < b)
					count++;
			}
		}
	}
	return count;
}


int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t=1;
	cin>>t;

	pair<vector<int>, vector<bool>> pair = sieve(1000*1000);

	while(t--)
	{
		int n, m;
		cin>>n>>m;
	
		ll count2 = 0;
		for (int b=2;b<=n;b++)
		{
			count2 += integer_multiples( m - m%b, b, pair.first, pair.second);	
		}
	
		cout<<count2;
		cout<<endl;
	}
	return 0;
}

void solve(){

}

