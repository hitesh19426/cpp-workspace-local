#include<bits/stdc++.h>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define endl '\n'
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
using namespace std;
void solve();

void show_queue(priority_queue<int> q)
{
	// priority_queue<int> q=pq;
	cout<<"queue: ";
	while (!q.empty())
	{
		cout<<q.top()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	map<int, int> umap;
	rep(i, n){
		int x;
		cin>>x;

		if (umap.find(x)==umap.end()){
			umap[x]=1;
		}
		else{
			umap[x]++;
		}
	}

	priority_queue<int> heap;
	for (auto itr=umap.begin();itr!=umap.end();itr++)
	{
		heap.push(itr->second);
	}

	while (heap.size()>1){
		int x=heap.top();
		heap.pop();
		int y=heap.top();
		heap.pop();

		if (x>1)
			heap.push(x-1);
		if (y>1)
			heap.push(y-1);
	}

	if (heap.empty()){
		cout<<0;
		return;
	}
	int last=heap.top();
	heap.pop();
	cout<<last;
}

