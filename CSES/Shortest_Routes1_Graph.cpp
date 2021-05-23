#include <bits/stdc++.h>
using namespace std;
void solve();

class min_heap
{
	int size;
	vector<pair<int, long long>> heap;	// node, dist type heap
	map<int, int> index;	// stores node, index in heap

	int parent(int i) { return (i-1)/2; }
	int left(int i) { return 2*i+1; }
	int right(int i) { return 2*i+2; }

	void rev_heapify(int key, int ind)
	{
		if(ind==0)
			return ;

		int p = parent(ind), p_key = heap[p].first;
		if(heap[p].second<=heap[ind].second)
			return ;

		swap(index[key], index[p_key]);
		swap(heap[p], heap[ind]);
		rev_heapify(key, p);
	}

	void heapify(int key, long long ind)
	{
		int min = ind;
		int l = left(ind), r = right(ind);
		
		if( l<size && heap[l].second<heap[min].second)
			min = l;
		if( r<size && heap[r].second<heap[min].second)
			min = r;
		if( min == ind)
			return ;

		swap( index[heap[ind].first], index[heap[min].first]);
		swap( heap[ind], heap[min]);

		heapify(key, min);			
	}

public:
	min_heap(int n)
	{
		size = 0;
		heap.reserve(n);
	}

	void push(int key, long long val)
	{
		heap.emplace_back(make_pair(key, val));
		index[key] = size;
		size++;

		rev_heapify(key, size-1);
	}

	// guaranted that new_value is less than original
	void decrease_value(int key, long long new_val)
	{
		int pos = index[key];
		heap[pos].second = new_val;

		rev_heapify(key, pos);
	}

	int front()
	{
		if(size==0)
			return -1;

		return heap[0].first;
	}

	void pop()
	{
		if(size==0)
			return ;

		size--;
		index[heap[0].first] = -1;
		index[heap[size].first] = 0;
		swap(heap[0], heap[size]);
		heapify(heap[0].first, 0);
	}

	bool empty()
	{
		if(size==0)
			return true;
		return false;
	}

	void printheap()
	{
		cout<<"Heap : \n";
		for(int i=0;i<size;i++)
			cout<<heap[i].first<<" : "<<heap[i].second<<endl;
	}

	void heapstate()
	{
		cout<<"Size : "<<size<<endl;
		cout<<"Heap size : "<<heap.size()<<endl;
		printheap();
		cout<<endl<<endl;
		cout<<"Index Map : "<<endl;
		for(auto ind:index)
			cout<<ind.first<<" "<<ind.second<<endl;
		cout<<endl<<endl;
	}
	
};


class Weighted_Graph
{
	int n;
	vector<vector<pair<int, int>>> graph;
	vector<int> parent;
public:
	Weighted_Graph(int _n)
	{
		n = _n;
		graph.resize(n);
		for(int i=0;i<n;i++)
			graph[i] = vector<pair<int, int>>();
	}

	void addEdge(int u, int v, int w)
	{
		graph[u].emplace_back(make_pair(v, w));
		// graph[v].emplace_back(make_pair(u, w));
	}

	void printGraph()
	{
		for(int i=0;i<(int)graph.size();i++)
		{
			cout<<i<<" : "<<" [ ";
			for(auto p : graph[i])
			{
				cout<<"("<<p.first<<", "<<p.second<<"), ";
			}
			cout<<"]\n";
		}
	}

	vector<long long> dijkstra(int src)
	{
		vector<long long> dist(n, LLONG_MAX);
		parent = vector<int>(n, -1);
		min_heap heap(n);

		for(int i=0;i<n;i++){
			if(i!=src)
				heap.push(i, dist[i]);
		}
		heap.push(src, 0LL);
		dist[src] = 0;


		while(!heap.empty()){
			int u = heap.front();
			heap.pop();

			for(auto v : graph[u]){
				if(dist[v.first] > dist[u] + v.second){
					dist[v.first] = dist[u] + v.second;
					parent[v.first] = u;
					heap.decrease_value(v.first, dist[v.first]);
				}
			}
		}

		return dist;
	}

	void print_vector(vector<long long> &dist) {
		cout<<"Distances : \n";
		for(int i=0;i<(int)dist.size();i++)
			cout<<i<<"\t"<<dist[i]<<endl;
	}
	void print_vector(vector<int> &parent) {
		cout<<"Parent : \n";
		for(int i=0;i<(int)parent.size();i++)
			cout<<i<<"\t"<<parent[i]<<endl;
	}
	void print_dijkstra(int src) {
		vector<long long> dist = dijkstra(src);
		for(int i=1;i<(int)dist.size();i++){
			// cout<<i<<"\t"<<dist[i]<<endl;
			cout<<dist[i]<<" ";
		}
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	// cin>>t;
	while(t--)
	{
		solve();
		cout<<endl;
	}

	return 0;
}

void solve()
{
	int n, m, src=1;
	cin>>n>>m;

	Weighted_Graph graph(n+1);

	for(int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;

		graph.addEdge(a, b, c);
	}

    graph.print_dijkstra(src);

}
