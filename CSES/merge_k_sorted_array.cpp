#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define ull unsigned long long
#define nline '\n'
#define INF INT_MAX
#define mod1 998244353
#define INFLL LLONG_MAX
#define PI 3.141592653589793238462

#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vpii vector<pair<int, int>>
#define pll pair<long long, long long>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

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

//----------------------------------------------------------------------------------------------------//

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

vector<int> merge(vector<int> &out1, vector<int> &out2){
	int p1=0, p2=0, n1=out1.size(), n2=out2.size();
	vector<int> out;
	while(p1<n1 && p2<n2){
		if(out1[p1]<out2[p2])
			out.push_back(out1[p1++]);
		else
			out.push_back(out2[p2++]);
	}

	while(p1<n1)
		out.push_back(out1[p1++]);

	while(p2<n2)
		out.push_back(out2[p2++]);
	return out;
}


vector<int> mergeArr(vector<vector<int>> &arr, int l, int r){
	if(l==r){
		return arr[l];
	}
	if(l+1==r){
		vector<int> out;
		out = merge(arr[l], arr[l+1]);
		return out;
	}

	int m=l+(r-l)/2;
	vector<int> out1, out2, out;
	out1 = mergeArr(arr, l, m);
	out2 = mergeArr(arr, m+1, r);

	out = merge(out1, out2);

	return out;
 }

void solve(){
	int k;
	cin>>k;

	vector<vector<int>> arr(k, vector<int>(k));
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			cin>>arr[i][j];
		}
	}
	print(arr);

	vector<int> out;
	out = mergeArr(arr, 0, k-1);
	print(out);
}
