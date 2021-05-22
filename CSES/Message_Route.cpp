#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

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

// vector<int> graph[200005];
#define N 200005
vector<vector<int>> graph(N+5, vector<int>(0));
vector<bool> vis(N+5, false);
vector<int> parent(N+5, -1); 
vector<int> dist(N+5, inf);
queue<int> q;

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
		// printf("\n");
		cout<<endl;
	}
	return 0;
}

void print_path(vector<int> &parent, int src, int dest)
{
	
	if(src==-1){
		return;
	}
 
	print_path(parent, parent[src], dest);
	cout<<src<<" ";
}

void solve(){
	int n, m;
	cin>>n>>m;

	// vector<vector<int>> graph(n+5, vector<int>());
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	
	// vector<bool> vis(n+5, false);
	// vector<int> parent(n+5, -1), dist(n+5, inf);
	int src = 1;
	int dest = n;

	q.push(src);
	vis[src] = true;
	dist[src] = 0;
	parent[src] = -1;

	while(!q.empty()){
		auto u = q.front();
		q.pop();

		for(auto v: graph[u]){
			if(!vis[v]){
				parent[v] = u;
				dist[v] = dist[u] + 1;
				vis[v] = true;
				q.push(v);
			}
		}
	}

	if(!vis[dest]){
		cout<<"IMPOSSIBLE";
		// printf("IMPOSSIBLE");
		return;
	}

	cout<<dist[dest]+1<<endl;
	// printf("%d\n", dist[dest]+1);

	// print(parent);
	print_path(parent, dest, src);

}

