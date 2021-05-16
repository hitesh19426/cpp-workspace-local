#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>


#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462

#define pb push_back
#define mp make_pair
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) cout<< #x << " = " << x << endl;
#define printarr(i, arr, n)	for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

void solve();
vll sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void algo(ll n){
	if (n==1){
		cout<<1<<" ";
		return ;
	}

	cout<<n<<" ";
	if (n%2==0){
		algo(n/2);
	}
	else{
		algo(3*n+1);
	}
}

void solve(){
	ll n;
	cin>>n;

	algo(n);
}
