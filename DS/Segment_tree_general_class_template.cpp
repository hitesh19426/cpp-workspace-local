#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve();

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
			return 0;

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
		return a + b;
	}
	
};


int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve()
{
	vector<int> arr = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10};
	Segment_tree<int, int> st(arr);

	cout<<st.range_query(0, 0)<<endl;
	cout<<st.range_query(3, 5)<<endl;
	cout<<st.range_query(0, 9)<<endl;

	st.updateValue(arr, 0, 2);
	cout<<st.range_query(0, 9)<<endl;
}
