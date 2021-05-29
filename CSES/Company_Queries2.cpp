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

class Tree
{
	int n;
	int LOG;
	const int root = 1;
	vector<int> parent;
	vector<int> depth;
	vector<vector<int>> up;
	vector<vector<int>> tree;
public:
	Tree(int n)
	{
		this->n = n;
		tree = vector<vector<int>>(n, vector<int>());
	}

	void addEdge(int u, int v)
	{
		tree[u].emplace_back(v);
		tree[v].emplace_back(u);
	}

	void bfs(int src)
	{
		parent = vector<int>(n, -1);
		vector<bool> vis(n, false);
		depth = vector<int>(n, INT_MAX);

		vis[src]=true;
		depth[src] = 0;
		queue<int> q;
		q.push(src);

		while(!q.empty())
		{
			int u = q.front();
			q.pop();

			for(int v : tree[u])
			{
				if(!vis[v]){
					vis[v] = true;
					depth[v] = depth[u]+1;
					parent[v] = u;
					q.push(v);
				}
			}
		}
	}

	void binary_lifting()
	{
		bfs(root);

		LOG = (int)ceil(log2(n)) + 1;
		up = vector<vector<int>>(n, vector<int>(LOG, 0));
		parent[root] = root;

		for(int i=1;i<n;i++)
			up[i][0] = parent[i];

		for(int j=1;j<LOG;j++)
			for(int i=1;i<n;i++)
				up[i][j] = up[up[i][j-1]][j-1];

	}

	// O(logn) using binary lifting
	int LCA(int a, int b)
	{
		if(depth[a]<depth[b])
			swap(a, b);
		
		int k = depth[a] - depth[b];
		for(int j=LOG-1; j>=0; j--)
			if( k & (1<<j))
				a = up[a][j];
		if(a==b)
			return a;
		

		for(int j=LOG-1;j>=0;j--)
		{
			if(up[a][j]!=up[b][j]){
				a = up[a][j];
				b = up[b][j];
			}
		}
		return up[a][0];
	}

};

void solve(){
	int n, q;
	cin>>n>>q;

	Tree tree(n+1);
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		tree.addEdge(i, x);
	}
	tree.binary_lifting();

	while(q--)
	{
		int a, b;
		cin>>a>>b;
		cout<<tree.LCA(a, b)<<endl;
	}


}

