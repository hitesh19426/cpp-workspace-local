#include <bits/stdc++.h>
using namespace std;
void solve();

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'

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

void print_path(vector<int> &parent, int src, int dest)
{
	if(src == -1)
		return;
 
	print_path(parent, parent[src], dest);
	cout<<src<<" ";
}

void solve(){
	int n, m;
	cin>>n>>m;

	vector<vector<int>> graph(n+5, vector<int>());
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	vector<bool> vis(n+5, false);
	vector<int> parent(n+5, -1), dist(n+5, INT_MAX);
	queue<int> q;
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
		return;
	}

	cout<<dist[dest]+1<<endl;
	print_path(parent, dest, src);
}

