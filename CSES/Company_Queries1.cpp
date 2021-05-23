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
		// cout<<endl;
	}
	return 0;
}

class Graph
{
	int n;
	int LOG;
	const int root = 1;
	const int LOG_MAX = 25;
	vector<vector<int>> graph;
	vector<vector<int>> up;
	vector<int> parent;
	vector<int> depth;
public:
	Graph(int _n)
	{
		n = _n;
		graph = std::vector<vector<int>>(n, std::vector<int>());
	}

	void addEdge(int u, int v)
	{
		graph[u].emplace_back(v);
	}

	void bfs(int src)
	{
		parent = vector<int>(n, -1);
		vector<bool> vis(n, false);
		depth = vector<int>(n, INT_MAX);

		queue<int> q;
		q.push(src);
		vis[src] = true;
		depth[src] = 0;

		while(!q.empty())
		{
			int u = q.front();
			q.pop();

			for(int v:graph[u])
			{
				if(!vis[v])
				{
					q.push(v);
					vis[v] = true;
					parent[v] = u;
					depth[v] = depth[u]+1;
				}
			}
		}
	}

	void binary_lifting()
	{
		LOG = (int) log2(n) + 1;
		up = vector<vector<int>>(n, vector<int>(LOG));
		bfs(root);

		parent[root] = root;
		for(int i=0;i<n;i++)
			up[i][0] = (parent[i]==-1 ? 0 : parent[i]);


		for(int j=1;j<LOG;j++)
			for(int i=0;i<n;i++)
				up[i][j] = up[ up[i][j-1] ][j-1];

		// cout<<"This step"<<endl;
		// print_up();
	}

	int kth_ancestor(int x, int k)
	{
		if(depth[x]<k || depth[x]==INT_MAX)
			return -1;

		for(int i=0;i<LOG;i++)
			if( k & (1<<i))
				x = up[x][i];

		return x;
	}

	void print_up()
	{
		for(int i=0;i<n;i++)
		{
			cout<<i<<" : ";
			for(int j=0;j<LOG;j++)
				cout<<up[i][j]<<" ";
			cout<<endl;
		}
	}

	void print_parent()
	{
		cout<<"parent : ";
		for(int i=0;i<n;i++)
			cout<<parent[i]<<" ";
		cout<<endl; 
	}

	void print_depth()
	{
		cout<<"depth : ";
		for(int i=0;i<n;i++)
			cout<<depth[i]<<" ";
		cout<<endl; 
	}
	
};

void solve(){
	int n, q;
	cin>>n>>q;

	Graph graph(n+1);
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		graph.addEdge(i, x);
		graph.addEdge(x, i);
	}

	graph.binary_lifting();
	// cout<<"After binary binary_lifting";
	// graph.print_up();
	// graph.print_parent();
	// graph.print_depth();

	while(q--)
	{
		int x, k;
		cin>>x>>k;

		cout<<graph.kth_ancestor(x, k)<<endl;
	}

}

