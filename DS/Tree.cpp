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

// unweighted, undirected (will work for direct too though)
class tree
{
public:
	int v;
	vector<vector<int>> graph;
	tree(int _v){
		v = _v;
		graph(v+1, vector<int>());
	}
	
	void addedge(int u, int v)
	{
		graph[u].pb(v);
		graph[v].pb(u);
	}
	

	void dfs(vector<bool> vis, int src)
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
	vector<int> bfs(int src)
	{
		vector<bool> vis(v+1, false);
		vector<long long> dist(v+1, inf_ll);
		vector<int> parent(v+1, -1);

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

	vector<int> path(vector<int> parent, int u)
	{
		vector<int> path;

		while (u!=-1)
		{
			path.pb(u);
			u = parent[u];
		}

		// will take logn only since path/vector contain only logn values
		reverse(path.begin(), path.end());
		return path;
	}

	int lcs(int u, int v, vector<int> parent)
	{
		vector<int> pathu = path(parent, u);
		vector<int> pathv = path(parent, v);

		int i;
		for (int i=0;i<pathu.size() && i<pathv.size();i++)
		{
			if (pathu[i]!=pathv[i])
				break;
		}
		return pathu[i-1];
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
