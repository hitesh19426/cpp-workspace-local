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

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



/*----------------------------------------------------------------------------------------------------*/

class SparseTable
{
	int n;
	int k=25;
	vector<vector<int>> st;
public:
	SparseTable(vector<int> arr)
	{
		n = arr.size();
		st.resize(n);

		for (int i=0;i<n;i++)
			st[i] = vector<int>(k+1);

		for (int i=0; i<n; i++)
			st[i][0] = arr[i];


		for (int j=1; j<=k; j++)
		{
			for (int i=0; i+(1<<j) < n ; i++)
				st[i][j] = min(st[i][j-1], st[i + (1<<(j-1)) ][j-1] );
		}

	}

	void printSparseTable()
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<k;j++)
			{
				cout<<st[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};



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
			return inf;

		int m = l + (r-l)/2;
		auto left = range_query_helper(a, b, l, m, 2*root+1);
		auto right = range_query_helper(a, b, m+1, r, 2*root+2);

		return op(left, right);
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
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n, q;
	cin>>n>>q;

	vector<int> arr;
	arr.resize(n);
	for (int i=0;i<n;i++) cin>>arr[i];

	// print(arr);
	Segment_tree<int, int> st(arr);

	// st.printSparseTable();
	while (q--)
	{
		int a, b;
		cin>>a>>b;
		a--;b--;

		cout<<st.range_query(a, b)<<endl;
	}

}

