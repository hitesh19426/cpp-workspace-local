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

// #define endl '\n'
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
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
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
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

int kth_zero(int l, int r, int k)
{
	if (r<l)
		return -1;

	if (l==r){
		int sum;
		cout<<"? "<<l+1<<" "<<l+1<<endl;
		cin>>sum;

		if (sum==0 && k==1)
			return l;
		else
			return -1;
	}

	int m = l+(r-l)/2;
	
	int sum;
	cout<<"? "<<l+1<<" "<<m+1<<endl;
	cin>>sum;

	// int ans = -1;
	int no_of_zero =  m-l+1 - sum;
	if ( no_of_zero >= k){
		return kth_zero(l, m, k);
	}
	else{
		return kth_zero(m+1, r, k - no_of_zero);
	}
}

void solve(){
	int n, t;
	cin>>n>>t;

	int k;
	cin>>k;
	int kth = kth_zero(0, n-1, k);
	cout<<"! "<<kth+1<<endl;
	t--;

	int last_k = k;
	int last_pos = kth;

	while (t--)
	{
		int k_inner;
		cin>>k_inner;
		
		int kth_inner;
		if (k_inner>=last_k)
			kth_inner = kth_zero(last_pos+1, n-1, k_inner-k+1);
		else
			kth_inner = kth_zero(0, last_pos-1, k_inner);
		
		cout<<"! "<<kth_inner+1<<endl;

		last_k = k_inner;
		last_pos = kth_inner;
	}
	

}

