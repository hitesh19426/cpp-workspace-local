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

class Graph
{
	int n;
	vector<vector<int>> graph;
	
public:
	Graph(int _n)
	{
		n = _n;
		graph = vector<vector<int>>(n, vector<int>());
	}

	void addEdge(int u, int v)
	{
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	
	void dfs(vector<int> &subnodes, int src, vector<bool> &vis)
	{
		if(vis[src])
			return ;

		int n = graph[src].size();
		vis[src] = true;
		if(n==0){
			return;
		}

		int count = 0;
		for(int i : graph[src]){
			if(!vis[i]){
				dfs(subnodes, i, vis);
				count += subnodes[i] + 1;
			}
		}
		subnodes[src] = count;
	}
	
};

void solve(){
	int n;
	cin>>n;

	Graph graph(n+1);
	for(int i=2;i<=n;i++){
		int x; cin>>x;
		graph.addEdge(i,x);
	}

	vector<int> subnodes(n+1, 0);
	vector<bool> vis(n+1, false);
	graph.dfs(subnodes, 1, vis);

	for(int i=1;i<=n;i++)
		cout<<subnodes[i]<<" ";

}

