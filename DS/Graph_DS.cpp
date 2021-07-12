#include <bits/stdc++.h>
using namespace std;

class Graph {
	class edge{
		int u, v, len;

		edge(int u, int v, int len) : u(u), v(v), len(len) {}
	}

	int n, m;
	// int x;
	vector<vector<pair<int, int>>> graph;
	vector<edge> edges;

	vector<long long> dist;
	vector<int> parent;
public:
	Graph(int n) : n(n), m(0), negcycle(false) {
		graph = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	}

	void addEdge(int u, int v, int w) {
		graph[u].emplace_back({v, w});
		edges.emplace_back(edge(u, v, w));
		m++;
	}

	void dijkstra(int src) {
		dist = vector<long long>(n, LLONG_MAX);
		parent = vector<int>(n, -1);

		set<pair<long long, int>> s;
		s.insert({0, src});
		dist[src] = 0;

		while(!s.empty()){
			int u=s.begin().second;
			s.erase(s.begin());

			for(auto x:graph[u]){
				int v=x.first;
				long long len=x.second;
				if(dist[v]>dist[u]+len){
					s.erase({dist[v], v});
					dist[v] = dist[u]+len;
					parent[v]=u;
					s.insert({dist[v], v});
				}
			}
		}
	}

	void bellman_ford(int src) {
		dist = vector<long long>(n, LLONG_MAX);
		parent = vector<int>(n, -1);
		dist[src]=0;
		
		int x;
		for(int i=0;i<n;i++)
		{
			x=-1;
			for(int e:edges) {
				if(dist[e.u]!=LLONG_MAX && dist[e.v]>dist[e.u]+e.len){
					dist[e.v] = dist[e.u]+e.len;
					parent[e.v] = parent[e.u];
					any = e.v;
				}
			}
			if(x==-1) break;
		}

		// no -ve cycle
		if(x==-1){
			return vector<int>();
		}

		for(int i=0;i<n;i++)
			x=parent[x];
		
		vector<int> cycle;
		for(int v=x; ; v=parent[v]){
			cycle.emplace_back(v);
			if(v==x && cycle.size()>1)
				break;
		}
		reverse(cycle.begin(), cycle.end());

	}

	/*call bellman ford before this function to initialize all 
	the distances. u should be same as src. */
	long long distance(int v) {
		return dist[v];
	}

	vector<int> path(int v) {
		vector<int> p;
		if(dist[v]==LLONG_MAX)
			return p;

		while(v!=-1){
			p.emplace_back(v);
			v=parent[v];
		}
		reverse(p.begin(), p.end());
		return p;
	}

	/*requires input as matrix. */
	void floyd_warshal(){
		vector<vector<long long>> d(n, vector<long long>());
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j]=graph[i][j];
			}
		}

		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;;j++){
					if(d[i][k]<INF && d[k][j]<INF)
						d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
	}

}