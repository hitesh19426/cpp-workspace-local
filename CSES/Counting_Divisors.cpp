#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'



#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>




#ifndef ONLINE_JUDGE
#define print(x) cerr<< #x << " = "; _print(x); cerr<<endl;
#else
#define print(x)
#endif

void _print(ll t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(string t) {cerr << t;}
template <class T, size_t N> void _print(T (&arr)[N]) {cerr << "[ "; for(T v:arr) { cerr<< (v) <<" "; } cerr<<"]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve();

/*----------------------------------------------------------------------------------------------------*/


vector<ll> sieve(int n)
{
	vector<bool> is_prime(n+1, true);
	vector<ll> primes;
	is_prime[0] = is_prime[1] = false;
	
	for (ll i=2;i<=n;i++) 
	{
		if (is_prime[i])
		{
			primes.emplace_back(i);
			for (ll j=i*i;j<=n;j+=i)
				is_prime[j]=false;
		}
	}

	return primes;
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

	vll primes = sieve(1000001);
	int k = primes.size();
	while(t--){
		int x;
		cin>>x;

		int prod = 1;
		for(int i=0; i<k && primes[i]<=x; i++)
		{
			int pow = 0;
			
			while(x%primes[i]==0){
				x /= primes[i], pow++;
			}

			prod *= (pow+1);
		}
		cout<<prod;
		cout<<endl;
	}
	return 0;
}
