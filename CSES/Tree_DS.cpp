#include<bits/stdc++.h>
using namespace std;

class Tree
{
/*
	Add bfs | dfs(from root) | diameter
	euler type1 | ST on euler | distance query | subnodes query
	euler type2 | path query | max node in path query
	binary lifting | kth ancestor | LCA(using binary lifting) | distance b/w two nodes
	euler type2 | is_ancestor() | binary lifting optimization 
	LCA (using RMQ) | Sparse Table

	Remaining : 
	euler type1  | ST on euler | distance query | subnodes query
	euler type2 (done) | path query | max node in path query
	euler1 | LCA (using RMQ) | Sparse Table (on euler1)

*/
	int n;
	const int root=1;			// Change as required
	vector<vector<int>> tree;	// everywhere
	vector<bool> vis;

	int LOG;					// binary lifting
	vector<int> depth;			// bfs
	vector<int> parent;			// bfs
	vector<vector<int>> up;		// binary lifting

	vector<int> in;				// euler type2
	vector<int> out;			// euler type2
	vector<int> euler2;			// euler type2
	// vector<int> flattree2;	// same as euler2

	vector<int> infirst;
	vector<int> outlast;
	vector<int> euler1;
	vector<int> logs2;
	vector<vector<int>> sparse;	// euler type 1, RMQ-LCA
public:
	Tree(int n)
	{
		this->n = n;
		tree = vector<vector<int>>(n, vector<int>());
	}

	/* Since it is a tree, hence double edge. */	
	void addEdge(int u, int v)
	{
		tree[u].emplace_back(v);
		tree[v].emplace_back(u);
	}

	/* initialize and store result in global depth/parent so 
	other functions can also use these values without problem/recalculation.
	Uses local vis.  */
	void bfs(int src)
	{
		/* initialize global vectors to save result*/
		depth = vector<int>(n, INT_MAX);
		parent = vector<int>(n, -1);
		vector<bool> vis(n, false);

		/* initialize queue and push src. update src values/parent*/
		depth[src] = 0;
		vis[src] = true;
		queue<int> q;
		q.push(src);

		/* update result for every unvisited outgoing node from latest node(u). */
		while(q.empty())
		{
			int u = q.front();
			q.pop();

			for(int v:tree[u])
			{
				if(!vis[v])
				{
					vis[v] = true;
					depth[v] = depth[u] + 1;
					parent[v] = u;
					q.push(v);
				}
			}
		}
	}

	void dfs(int src)
	{
		vis = vector<bool>(n, false);
		dfs(src, vis);
	}

	/* make sure to empty vis before calling this. */
	void dfs(int src, vector<bool> &vis)
	{
		if(vis[src])
			return ;

		vis[src] = true;
		cout << src << " ";	// do something with dfs order

		for(int v : tree[src])
		{
			if(!vis[v]){
				dfs(v, vis);
			}
		}
	}

	/* assuming given root or any other other node can be passed in bfs if not. */
	int diameter()
	{
		/* run bfs from a vertex(root here) and find furthest vertex.*/
		bfs(root);
		int node=-1, dist_max=-1;
		for(int i=0;i<n;i++)
		{
			if(depth[i]>dist_max){
				node = i;
				dist_max = depth[i];
			}
		}

		/* run bfs from vertex find above and find maximum distance -- this dist is diameter */
		bfs(node);
		int diameter=-1;
		for(int i=0;i<n;i++){
			if(diameter<depth[i]){
				diameter = depth[i];
			}
		}

		return diameter;
	}

	/* Assuming 1 indexing here(no 0 node and n+1 tree size). To make it 0 indexing
	just loop from i=0. This function Assigns up array to calculate ancestors quickly. */
	void binary_lifting()
	{
		/*This can be taken as LOGMAX = 20 also. */
		LOG = (int)ceil(log2(n))+1;
		parent[root] = root;
		up = vector<vector<int>>(n, vector<int>(LOG));

		/* Base Case dp for filinf up */
		for(int i=1;i<n;i++){
			up[i][0]=parent[i];
		}

		/* General dp for filing up */
		for(int j=1;j<LOG;j++)
			for(int i=1; i<n; i++)
				up[i][j] = up[ up[i][j-1] ][j-1];

	}

	/* Make sure to call binary_lifting before using this function. 
		returns -1 if ancestor not found. change it as required. */
	int kthancestor(int x, int k){
		if(depth[x]<k)
			return -1;

		/* This loop can be run from forward also. It does not matter if 
		you do 19 = 1+2+16 or 16+2+1(below). */
		for(int j=LOG; j>=0; j--){
			if( k & (1<<j)){
				k = up[x][j];
			}
		}
		return k;
	}

	/* Return LCA of a, b as taught by Errichto(youtube). O(logn)*/
	int LCA(int a, int b){
		/* Assign deeper root as a */
		if(depth[a]<depth[b])
			swap(a, b);

		/* This will bring a and b to same level. */
		int k = depth[a]-depth[b];
		for(int j=LOG; j>=0; j--)
			if(k & (1<<j))
				a = up[a][j];

		/* Check if b is ancestor itself. */
		if(a==b)
			return a;

		/* Lift both nodes until their parent is LCA. */
		for(int j=LOG; j>=0; j--){
			if(up[a][j]!=up[b][j]){
				a=up[a][j];
				b=up[b][j];
			}
		}
		return up[a][0];
	}

	/* This takes O(logn) time since LCA takes O(logn) time. Use RMQ+Euler for O(1). */ 
	int distance(int a, int b){
		return depth[a] + depth[b] - 2*depth[LCA(a, b)];
	}

	/* call this for euler2, assigns necessary arrays and then automatically call euler_dfs.
	 dont call this repetedly. Use this to initialize euler2 only. */
	void eulertype2()
	{
		in = vector<int>(n, -1);
		out = vector<int>(n, -1);
		vis = vector<bool>(n, false);
		int time = 0;

		euler_dfs(root, vis, time);
	}

	/* Insert leaf node twice */
	void euler_dfs(int src, vector<bool> &vis, int &time)
	{
		if(vis[src])
			return ;

		vis[src] = true;
		in[src]=time;
		euler2.emplace_back(src);

		for(int v:tree[src]){
			if(!vis[v])
				euler_dfs(v, vis, ++time);
		}

		out[src] = ++time;
		euler2.emplace_back(src);
	}

	/* Returns if a is an ancestor of b or not */
	bool is_ancestor(int a, int b)
	{
		if(in[a]<in[b] && out[b]<out[a])
			return true;
		return false;
	}

	/* This function uses euler2 in/out to check ancestor and then return LCA.
		RMQ is different -- O(logn)  */
	int LCA_euler(int a, int b)
	{
		if(is_ancestor(a, b))
			return a;
		if(is_ancestor(b, a))
			return b;

		for(int j=LOG; j>=0; j--){
			if(!is_ancestor(b, up[a][j])){
				a=up[a][j];
			}
		}
		return up[a][0];
	}

	/* Would need min ST to calculate min in O(logn)/ Sparse table for O(1).
	Both need to be built on euler2 -- not in/out/tree.
	So you cant use up since it is built on tree -- not euler2/flattree2. 
	Will implement later, will take lots and lots of code for ST/Sparse. */
	/* call range min sparse before using this. need to be tested. */
	int LCA_RMQ(int a, int b)
	{
		return RMQ(infirst[a], infirst[b]);
	}

	void eulertype1()
	{
		infirst = vector<int>(n, -1);
		outlast = vector<int>(n, -1);
		vis = vector<bool>(n, false);
		int time = 0;

		euler1_dfs(src, time);
	}

	euler1_dfs(int src, int &time)
	{
		if(vis[src])
			return ;

		vis[src] = true;
		infirst[src]=time;
		euler1.emplace_back(src);

		for(int v:tree[src]){
			if(!vis[v]){
				euler1_dfs(v, ++time);
				euler1.emplace_back(src);
			}
		}

		outlast[src] = ++time;
		euler1.emplace_back(src);
	}

	void RMQ_Sparse()
	{
		int _n = euler1.size();
		int LOGsparse = (int)ceil(log2(_n));
		sparse = vector<vector<int>>(_n, vector<int>(LOGsparse));

		for(int i=0; i<_n; i++)
			sparse[i][0] = euler1[i];

		for(int j=1; j<LOGsparse; j++){
			for(int i=0; i<_n && ( i+(1<<j) <= _n); i++){
				sparse[i][j] = min( sparse[i][j-1], sparse[ i + (1<<(j-1)) ][j-1]);
			}
		}

		logs2[1] = 0;
		for(int i=2;i<n;i++)
			log2[i] = logs2[i/2]+1;
	}

	int RMQ(int a, int b)
	{
		if(b<a)
			swap(a, b);

		int k = log2(b-a+1);
		return min( sparse[a][k], sparse[b-(1<<k)+1][k]);
	}
	
};



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}