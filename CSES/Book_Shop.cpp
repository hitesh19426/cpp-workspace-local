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

int ways(vvi &dp, vi &prices, vi &pages, int n, int x)
{
	if(dp[n][x]!=-1)
		return dp[n][x];

	if(x-prices[n-1]>=0){
		dp[n][x] = max(ways(dp, prices, pages, n-1, x), pages[n-1] + ways(dp, prices, pages, n-1, x-prices[n-1]) );
	}
	else{
		dp[n][x] = ways(dp, prices, pages, n-1, x);
	}

	return dp[n][x];
}

void solve(){
	int n, x;
	cin>>n>>x;

	vi prices(n);
	rep(i, n) cin>>prices[i];

	vi pages(n);
	rep(i, n) cin>>pages[i];

	vvi dp(n+1, vi(x+1, -1));
	for(int i=0;i<=n;i++)
		dp[i][0] = 0;
	for(int i=0;i<=x;i++)
		dp[0][i] = 0;
	
	cout << ways(dp, prices, pages, n, x);
}

