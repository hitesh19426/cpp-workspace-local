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

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
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
		// cout<<endl;
	}
	return 0;
}

void solve(){
	int n, q;
	cin>>n>>q;

	string s[n];
	for (int i=0;i<n;i++) cin>>s[i];

	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (s[i-1][j-1] == '*')
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + 1;
			else
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}

	// for (int i=0;i<=n;i++)
	// {
	// 	for (int j=0;j<=n;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }

	while (q--)
	{
		int y1, x1, y2, x2;
		cin>>y1>>x1>>y2>>x2;

		swap(x1, y1);
		swap(x2, y2);

		int ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] +dp[x1-1][y1-1];
		cout<<ans<<endl;
	}
}

