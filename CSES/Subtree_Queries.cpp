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
	const int root = 1;
	vector<vector<int>> tree;
	vector<int> in;
	vector<int> out;
	vector<int> flattree;
	vector<bool> vis;
	vector<long long> st;
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

	void euler()
	{
		in = vector<int>(n, -1);
		out = vector<int>(n, -1);
		vis = vector<bool>(n, false);

		int time = 0;
		euler_dfs(root, time);
	}

	void euler_dfs(int src, int &time)
	{
		if(vis[src])
			return ;

		vis[src] = true;
		in[src] = time;
		flattree.emplace_back(src);

		for(int v : tree[src]){
			if(!vis[v]){
				euler_dfs(v, ++time);
			}
		}

		out[src] = ++time;
		flattree.emplace_back(src);
	}

	void buildST(vector<int> &values)
	{
		int _n = flattree.size();
		int h = (int)ceil(log2(_n));
		int size = (1<<(h+1)) - 1;

		st = vector<long long>(size);
		fillST(values, 0, _n-1, 0);
	}

	void fillST(vector<int> &values, int l, int r, int root)
	{
		if(l==r){
			st[root] = values[flattree[l]];
			return ;
		}

		int m = l+(r-l)/2;
		fillST(values, l, m, 2*root+1);
		fillST(values, m+1, r, 2*root+2);

		st[root] = st[2*root+1] + st[2*root+2];
	}

	void update_value(vector<int> &values, int s, int x)
	{
		values[s] = x;
		updatetree(0, flattree.size()-1, in[s], x, 0);
		updatetree(0, flattree.size()-1, out[s], x, 0);
	}

	void updatetree(int l, int r, int ind, int val, int root)
	{
		if(ind<l || r<ind)
			return ;
		if(l==r){
			st[root] = val;
			return ;
		}

		int m = l+(r-l)/2;
		updatetree(l, m, ind, val, 2*root+1);
		updatetree(m+1, r, ind, val, 2*root+2);
		st[root] = st[2*root+1] + st[2*root+2];
	}

	long long sum_query(int node)
	{
		return query_helper(0, flattree.size()-1, in[node], out[node], 0)/2;
	}

	long long query_helper(int l, int r, int a, int b, int root)
	{
		if(b<l || r<a)
			return 0;
		if(a<=l && r<=b)
			return st[root];

		int m = l+(r-l)/2;
		return query_helper(l, m, a, b, 2*root+1) + query_helper(m+1, r, a, b, 2*root+2);
	}

	void printST()
	{
		// print(st);
		for (int i=0;i<(int)st.size();i++){
			cout<<st[i]<<" ";
		}
		cout<<endl;
	}

	void print_euler()
	{
		// print(tree);
		print(in);
		print(out);
		print(flattree);
	}

};
void solve(){
	int n, q;
	cin>>n>>q;

	Tree tree(n+1);
	vector<int> values(n+1, 0);
	for(int i=1;i<=n;i++)
		cin>>values[i];

	for(int i=1;i<n;i++){
		int a, b;
		cin>>a>>b;
		tree.addEdge(a, b);
	}
	tree.euler();
	tree.buildST(values);
	// tree.printST();

	while(q--)
	{
		int query;
		cin>>query;

		if(query==1){
			int s, x;
			cin>>s>>x;

			tree.update_value(values, s, x);
			// tree.printST();
		}
		else{
			int s;
			cin>>s;
			cout<<tree.sum_query(s)<<endl;
		}
	}
}

