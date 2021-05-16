#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long

#define endl '\n'
#define pb push_back
#define mp make_pair

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) cout<< #x << " = " << x << endl;
#define printarr(i, arr, n)	for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

void solve();
/*----------------------------------------------------------------------------------------------------*/

// Considering directed for now, to make undirected, just insert edge u, v and v, u
class unweighted_graph
{
public:
	int v;
	vvi graph;
	unweighted_graph(int _v){
		v = _v;
		graph(v+1, vi());
	}
	
	void addedge(int u, int v)
	{
		graph[u].pb(v);
		// graph[v].pb(u);
	}

	void dfs(vb vis, int src)
	{
		if (vis[src]) return ;

		vis[src] = true;
		print(src);

		for (auto itr=graph[src].begin();itr!=graph[src].end();itr++)
		{
			dfs(vis, *itr);
		}
	}

	// can be optimsed to find parent or distance only.
	vi bfs(int src)
	{
		vb vis(v+1, false);
		vll dist(v+1, inf_ll);
		vi parent(v+1, -1);

		vis[src] = true; dist[src] = 0;
		queue<int> q;
		q.push(src)

		while (!q.empty())
		{
			auto v = q.front();
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

		return parent;
		// return dist
		// for calculating distances
	}

	// may not work for unconnected graph
	bool detectCycle(vb vis, int src)
	{
		if (vis[src]) return true;

		vis[node] = true;

		for (auto itr=graph[v].begin();itr!=graph[v].end();itr++)
		{
			dfs(vis, *itr);
		}

		vis[node] = false;
		return false;
	}

	// return sum of lengths of connected components
	ll connected_sum()
	{
		ll sum = 0;
		vb vis(v+1, false);

		for (int i=1;i<=n;i++)
		{
			if (!vis[i])
			{
				sum += dfs_for_connected_sum(i, vis);
			}
		}
	}

	ll dfs_for_connected_sum(int i, vb vis)
	{
		if (!vis[i]) return 0;

		ll sum = 1;
		for (auto itr=graph[i].begin();itr!=graph[i].end();itr++)
		{
			sum += dfs_for_connected_sum(*itr, vis);
		}

		return sum;
	}

};


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

void solve(){
	
}
