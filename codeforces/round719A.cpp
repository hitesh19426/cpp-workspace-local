#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define mod 1000000007
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462

#define pb push_back
#define mp make_pair
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
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
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


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
	int n;
	cin>>n;

	bool vis[26]={false};
	char last;
	string str;
	cin>>str;

	// for (int i=0;i<26;i++)
	// 	cerr<< vis[i] <<" ";
	// cerr<<endl;

	
	for (int i=0;i<n;i++)
	{
		char ch = str[i];
		// cout<<(char)last<<endl;
		// cout<<(char)ch<<endl;

		if (!vis[(int)(ch-'A')]){
			vis[(int)(ch-'A')] = true;
			last = ch;
			// cout<<"first if"<<endl;
		}
		else if (ch == last){
			// cout<<"second if"<<endl;
			continue;
		}
		else{
			// cout<<"last if"<<endl;
			cout<<"NO";
			return;
		}

		// cout<<last<<endl;
		// cout<<ch<<endl;
	}

	cout<<"YES";
}

