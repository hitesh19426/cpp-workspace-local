#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'



#define nline '\n'
#define inf 1000000000
#define mod 1000000007
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462


#define pb push_back
#define mp make_pair
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve();

#ifndef ONLINE_JUDGE
#define print(x) cerr<< #x << " = "; _print(x); cerr<<endl;
#else
#define print(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

/*----------------------------------------------------------------------------------------------------*/



template<class T, class Q>
class Segment_tree
{
	vector<Q> tree;
	int n, h, size;
public:
	Segment_tree(vector<T> &arr)
	{
		n = arr.size();
		h = (int) ceil(log2(n));
		size=(int) pow(2, h+1)-1;

		tree.resize(size);
		fillST(arr, 0, n-1, 0);
	}

	void fillST(vector<T> &arr, int l, int r, int root)
	{
		if (l==r){
			tree[root] = arr[l];
			return ; 
		}

		int m = l+(r-l)/2;

		fillST(arr, l, m, 2*root+1);
		fillST(arr, m+1, r, 2*root+2);

		tree[root] = op(tree[2*root+1], tree[ 2*root+2]);
	}

	Q range_query(int a, int b)
	{
		if (b<0 || a>n-1 || b<a){
			return -1;
		}

		return range_query_helper(a, b, 0, n-1, 0);
	}

	Q range_query_helper(int a, int b, int l, int r, int root)
	{
		if (a<=l && r<=b)
			return tree[root];
		if (b<l || r<a)
			return default_value();

		int m = l + (r-l)/2;
		auto left = range_query_helper(a, b, l, m, 2*root+1);
		auto right = range_query_helper(a, b, m+1, r, 2*root+2);

		return op(left, right);
	}

	Q default_value()
	{
		return inf;
	}

	void updateValue(vector<T> &arr, int ind, T new_value)
	{
		if (ind<0 || ind>n-1)
			return ;

		arr[ind] = new_value;
		updateTree(ind, new_value, 0, n-1, 0);
	}

	void updateTree(int ind, T new_value, int l, int r, int root)
	{
		if (ind<l || r<ind)
			return ;

		if (l==r){
			tree[root] = new_value;
			return ;
		}

		int m = l + (r-l)/2;
		updateTree(ind, new_value, l, m, 2*root+1);
		updateTree(ind, new_value, m+1, r, 2*root+2);

		tree[root] = op(tree[2*root+1], tree[2*root+2]);
	}

	void printST()
	{
		for (int i=0;i<size;i++){
			cout<<tree[i]<<" ";
		}
		cout<<endl;
	}

	Q op(Q &a, Q &b)
	{
		return min(a, b);
	}
	
};




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
		// cout<<endl;
	}
	return 0;
}

void solve(){
	int n, q;
	cin>>n>>q;

	vector<int> arr;
	arr.resize(n);

	for (int i=0;i<n;i++) cin>>arr[i];

	Segment_tree<int, int> st(arr);

	while(q--)
	{
		int q;
		cin>>q;

		if (q==1){
			int k, u;
			cin>>k>>u;
			k--;

			st.updateValue(arr, k, u);

		}
		else{
			int a, b;
			cin>>a>>b;
			a--;b--;

			cout<<st.range_query(a, b)<<endl;
		}
	}

}

