#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

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

void solve(){
	int n, x;
	cin>>n>>x;

	int arr[n];
	rep(i, n) cin>>arr[i];

	vector<ll> sum(n); ll count=0;
	rep(i, n){ 
		sum[i] = ( i==0 ? arr[i] : arr[i]+sum[i-1]);
		if(sum[i]==x)
			count++;
	}

	print(sum);

	int ind = lower_bound(sum.begin(), sum.end(), x)-sum.begin();
	print(ind);
	for(int i=ind;i<n;i++){
		if(binary_search(sum.begin(), sum.begin()+i, abs(x-sum[i])))
			count++;
	}

	// for(int i=1;i<n;i++){
	// 	if(binary_search(sum.begin(), sum.begin()+i, sum[i]-x)){
	// 		count++;
	// 		print(i);
	// 	}
	// }

	cout<<count;
	cerr<<endl;

}

