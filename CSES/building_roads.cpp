#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//----------------------------------------------------------------------------------------------------//

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

vector<vector<int>> graph;

void dfs(int src, vector<bool> &vis){
	if(vis[src])
		return ;

	vis[src] = true;
	for(int v: graph[src]){
		if(!vis[v])
			dfs(v, vis);
	}
}

void solve(){
	int n, m;
	cin>>n>>m;

	graph.resize(n+5);
	fill(graph.begin(), graph.end(), vector<int>());
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<bool> vis(n+5, false);
	vector<int> components;

	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i, vis);
			components.push_back(i);
		}
	}

	int ans = components.size()-1;
	cout << ans << endl;
	for(int i=0; i<ans; i++)
		cout << components[i] << " " << components[i+1] << endl;
}
