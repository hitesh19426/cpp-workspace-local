#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define mod 1000000000 + 7
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462

#define pb push_back
#define mp make_pair
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) cout<< #x << " = " << x << endl;
#define printarr(i, arr, n)	for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

void solve();
vll sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
	int t=1;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}


// root to vertex
vi path(int parent[], int u)
{
	vi p;
	while (u!=-1)
	{
		p.pb(u);
		u = parent[u];
	}

	reverse(p.begin(), p.end());
	return p;
}

int LCA(int parent[], int u, int v)
{
	vi pathu = path(parent, u);
	vi pathv = path(parent, v);

	int i;
	for (i=0;i<pathu.size() && i<pathv.size();i++)
	{
		if (pathu[i]!=pathv[i])
			break;
	}
	return pathu[i-1];
}

ll distance(ll dist[], int u, int v, int src, int parent[])
{
	if (u==src || v==src)
	{
		return max(dist[u], dist[v]);
	}

	return dist[u] + dist[v] - 2*dist[LCA(parent, u, v)];
} 

void solve(){
	int n, k, a;
	cin>>n>>k>>a;

	// print(n);
	// print(k);
	// print(a);

	int f[k];
	rep(i, k){ 
		cin>>f[i];
	}

	// rep(i, k){
	// 	cout<<f[i]<<" ";
	// }
	// cout<<endl;


	vvi graph;
	rep(i, n+1) graph.pb(vi(0));

	rep(i, n-1){
		int u, v;
		cin>>u>>v;

		graph[u].pb(v);
		graph[v].pb(u);
	}

	// rep(i, n+1)
	// {
	// 	cout<<i<<": ";
	// 	for (auto itr=graph[i].begin();itr!=graph[i].end();itr++)
	// 	{
	// 		cout<<*itr<<" ";
	// 	}
	// 	cout<<endl;
	// }

	ll dist[n+1];
	bool vis[n+1];
	int parent[n+1];

	rep(i, n+1){
		dist[i] = inf_ll;
		vis[i] = false;
		parent[i] = -1;
	}
	vis[a] = true;
	dist[a] = 0;
	parent[a] = -1;

	queue<int> q;
	q.push(a);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		for (auto itr=graph[v].begin();itr!=graph[v].end();itr++)
		{
			if (!vis[*itr])
			{
				q.push(*itr);
				vis[*itr] = true;
				dist[*itr] = dist[v] + 1;
				parent[*itr] = v;
			}
		}
	}

	// printarr(i, dist, n+1);
	// printarr(i, vis, n+1);


	vi nodes;
	for (int b=1;b<=n;b++)
	{
		ll dist_max = -inf_ll;
		int node = -1;
		// print(b);
		for (auto u:f)
		{
			// print(u);
			auto di = distance(dist, a, u, a, parent) - distance(dist, b, u, a, parent) ;
			
			// print(di);
			if (dist_max < di){
				node = u;
				dist_max = di;
			}
			
		}
		nodes.pb(node);
		// cout<<endl;
		cout<<dist_max<<" ";
	}
	cout<<endl;

	foreach(i, nodes)
		cout<<*i<<" ";


}
