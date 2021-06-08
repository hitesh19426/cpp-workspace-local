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

int N, dia1, dia2;
vector<vector<int>> tree;
vector<vector<int>> up;

vector<bool> vis;
vector<int> depth;
vector<int> parent;

int cur_pos=0;
vector<int> heavy;	// who is the heavy child of each node
vector<int> head;
vector<int> pos;
vector<int> st2;

void addEdge(int a, int b){
	tree[a].eb(b);
	tree[b].eb(a);
}

// assign heavy to each node, parent, depth
// heavy tells who is the heavy child of each node
int dfs(int u) {
	int size =1;
	int max_child_size=0;
	vis[u]=true;

	for(int v:tree[u]){
		if(!vis[v]){
			parent[v]=u, depth[v]=depth[u]+1;
			int c_size=dfs(v);
			size += c_size;
			if(c_size > max_child_size)
				max_child_size = c_size, heavy[v]=c;
		}
	}

	return size;
}

void decompose(int v, int h){
	head[v] = h, pos[v]=cur_pos++;
	if(heavy[v]!=-1)
		decompose(heavy[v], h);
	for(int c:tree[v]){
		if(c!=parent[v] && c!=heavy[v])
			decompose(c, c, adj);
	}

}

void heavy_light(int root){
	parent = vector<int>(N, -1);
	depth = vector<int>(N);
	heavy = vector<int>(N, -1);
	head = vector<int>(N);
	pos = vector<int>();

	dfs(root);
	decompose(root, root);
}

void solve(){
	int n, q;
	cin>>n>>q;
	N=n+1;

	vector<int> values(n+1);
	for(int i=1;i<n+1;i++)
		cin>>values[i];

	tree = vector<vector<int>>(n+1, vector<int>());
	for(int i=1;i<n;i++){
		int a, b;
		cin>>a>>b;
		addEdge(a, b);
	}
	// euler2();
	// buildST(values);
	
	while(q--){
		int query, s, x, a, b;
		cin>>query;

		if(query==1){
			cin>>s>>x;
			// update(values, s, x);
		}
		else{
			cin>>a>>b;
			// cout<<rangequery(a, b)<<" ";
		}
	}

}

//1 9 10 10 9 9 





/*
void euler2_dfs(int src, vector<bool>& vis, int &time)
{
	if(vis[src])
		return ;

	vis[src]=true;
	in[src]=time++;
	flattree.eb(src);

	for(int v:tree[src]){
		if(!vis[v]){
			euler2_dfs(v, vis, time);
		}
	}

	out[src] = time++;
	flattree.eb(src);
}

void euler2(int src=1) {
	vis = vector<bool>(N, false);
	in = vector<int>(N, -1);
	out = vector<int>(N, -1);
	int time=0;

	euler2_dfs(src, vis, time);
}

void fillST(vector<int> &values, int l, int r, int root){
	if(l==r){
		st2[root]=values[flattree[l]];
		return;
	}

	int m=l+(r-l)/2;
	fillST(values, l, m, 2*root+1);
	fillST(values, m+1, r, 2*root+2);
	st2[root] = max(st2[2*root+1], st2[2*root+2]);
}

void buildST(vector<int> &values){
	int n = flattree.size();
	st2.resize(4*n);
	fillST(values, 0, flattree.size()-1, 0);
}

int rangequery(int l, int r, int a, int b, int root){
	if(a<=l && r<=b)
		return st2[root];
	if(b<l || r<a)
		return -1;

	int m=l+(r-l)/2;
	return max(rangequery(l, m, a, b, 2*root+1), rangequery(m+1, r, a, b, 2*root+2));
}

int rangequery(int a, int b){
	int x = min(in[a], in[b]);
	int y = max(in[a], in[b]);
	print(a);
	print(b);
	print(x);
	print(y);
	return rangequery(0, flattree.size()-1, x, y, 0);
}

void updateTree(int l, int r, int ind, int val, int root){
	if(ind<l || ind>r)
		return ;

	if(l==r){
		st2[root]=val;
		return ;
	}

	int m=l+(r-l)/2;
	updateTree(l, m, ind, val, 2*root+1);
	updateTree(m+1, r, ind, val, 2*root+2);
	st2[root] = max(st2[2*root+1], st2[2*root+2]);
}

void update(vector<int>& values, int s, int val){
	values[s]=val;
	updateTree(0, flattree.size()-1, in[s], val, 0);
	updateTree(0, flattree.size()-1, out[s], val, 0);
}
*/