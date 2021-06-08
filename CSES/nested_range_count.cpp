#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define mod 1000000007
#define mod1 998244353
#define inf_ll (ll)1e18
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
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


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

int N;
vi bit;
// assuming ind to be 0 based (can be 0)
void add(int ind, int val){
	for(++ind; ind<=N; ind += ind & -ind)
		bit[ind] += val;
}
int sum(int ind){
	int ans=0;
	for(++ind; ind>0; ind -= ind & -ind)
		ans += bit[ind];
	return ans;
}

void solve(){
	int n;
	cin>>n;

	vpii entry(n), exit(n);
	vi sortind(n);
	rep(i, n){
		cin>>entry[i].ff>>exit[i].ff;
		entry[i].ss=exit[i].ss=i;
	}

	sort(exit.begin(), exit.end(), [&entry](pii &a, pii &b) -> bool{
		if(a.ff!=b.ff)
			return a.ff<b.ff;
		return entry[a.ss].ff>entry[b.ss].ff;
	});
	sort(entry.begin(), entry.end());
	for(int i=0;i<n;i++)
		sortind[entry[i].ss]=i;


	int p1=0, p2=0;
	bit.assign(n+1, 0);
	N=n+1;
	vi ans1(n, 0), ans2(n, 0);
	// print(bit);
	while(p1<n){
		if(entry[p1].ff<exit[p2].ff){
			add(p1, 1);
			p1++;
		}
		else{
			int ind=sortind[exit[p2].ss];
			add(ind, -1);	//startid is exit[p2].ss --> sortind[id]
			int x = sum(ind);
			ans1[exit[p2].ss]=x;
			p2++;
		}
	}

	while(p2<n){
		int ind=sortind[exit[p2].ss];
		add(ind, -1);
		int x = sum(ind);
		ans1[exit[p2].ss]=x;
		p2++;
	}
	// print ans1;
	// print(ans1);

	// print(ans2)
	// print(bit)
	p2=0;
	while(p2<n){
		int ind = sortind[exit[p2].ss];
		int x = sum(n-1)-sum(ind);
		add(ind, 1);
		ans2[exit[p2].ss]=x;
		p2++;
	}
	// print(ans2);
	
	for(int i:ans2)
		cout<<i<<" ";
	cout<<endl;
	for(int i:ans1)
		cout<<i<<" ";


}

/*
4
1 6
2 4
4 8
3 6

*/