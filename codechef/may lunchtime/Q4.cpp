#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pll pair<long long, long long>

#define endl '\n'
#define nline '\n'
#define inf INT_MAX
#define mod 1000000007
#define mod1 998244353
#define inf_ll LLONG_MAX
#define PI 3.141592653589793238462
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()

#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

pair<int, int> maxsubarray(vector<long long> &arr, int l, int r)
{
	if(r<0 || l>=(int)arr.size() || r<l)
		return make_pair(-1, -1);
	if(l==r)
		return make_pair(l, l);

	vector<long long> dp(r-l+1), left(r-l+1), right(r-l+1);
	dp[0]=arr[l], left[0]=l, right=l;
	long long ans=arr[l];
	for(int i=l+1;i<=r;i++){
		dp[i] = max(arr[i], dp[i-1]+arr[i]);
		if(dp[i]==arr[i])
			left[i]=i;
		else
			left[i] = left[i-1];
		
		if(ans<dp[i]){
			ans = dp[i];
			right = i;
		}

	}
	return make_pair(left[right], right);
}

void solve(){
	int n, k;
	cin>>n>>k;

	vector<long long> arr(n), sum(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		sum[i] = (i==0 ? arr[i] : sum[i-1]+arr[i]);
	}

	cout<<ans;
}
