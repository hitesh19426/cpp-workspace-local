#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve();

/* The functions required for segment tree construction, range query and update function*/
vector<int> buildST(vector<int> &arr, int n);
int range_query(vector<int> &st, int n, int a, int b);
int range_query_helper(vector<int> &st, int a, int b, int l, int r, int root);
void updateValue(vector<int> &tree, vector<int> &arr, int n, int ind, int new_value);
void updateTree(vector<int> &tree, int l, int r, int ind, int new_value, int root);
void fillST(vector<int> &arr, vector<int> &tree, int l, int r, int root);
void printST(vector<int> &tree, int n);
/* The functions required for segment tree construction, range query and update function*/

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
	int n = arr.size();
	int h = (int) ceil(log2(n));
	int size=(int) pow(2, h+1)-1;

	vector<int> tree = buildST(arr, n);

	// tree, n, a, b: query range [a, b]
	// printST(tree, size);

	// cout<<range_query(tree, n, 0, 0)<<endl;
	// cout<<range_query(tree, n, 0, n-1)<<endl;

	// tree, arr, n, ind, new_value
	// updateValue(tree, arr, n, 0, 2);
	// cout<<range_query(tree, n, 0, n-1)<<endl;

	Segment_tree<int, int> st(arr);
	cout<<st.range_query(0, 0)<<endl;
	cout<<st.range_query(3, 5)<<endl;
	cout<<st.range_query(0, 9)<<endl;

	st.updateValue(arr, 0, 2);
	cout<<st.range_query(0, 9)<<endl;
}



/*This ST is for sum query.*/

/*
The function which build the segement tree.
Note: Make sure to create pointer of ll if answer can go to ll and change type of fillST too.
*/

vector<int> buildST(vector<int> &arr, int n)
{
	int h = (int) ceil(log2(n));
	int size=(int) pow(2, h+1)-1;

	vector<int> tree(size);
	fillST(arr, tree, 0, n-1, 0);

	return tree;
}

/*
This is the function that fills the values in the segment tree.
Note: Make sure type of function is ll if answer can go to ll.
*/
void fillST(vector<int> &arr, vector<int> &tree, int l, int r, int root)
{
	if (l==r){
		tree[root] = arr[l];
		return ; 
	}

	int m = l+(r-l)/2;

	fillST(arr, tree, l, m, 2*root+1);
	fillST(arr, tree, m+1, r, 2*root+2);

	tree[root] = tree[2*root+1] + tree[ 2*root+2];
}


/*This function return query in the range from a to b include*/
int range_query(vector<int> &st, int n, int a, int b)
{
	// wrong query basically
	if (b<0 || a>n-1 || b<a){
		return -1;
	}

	return range_query_helper(st, a, b, 0, n-1, 0);
}

/*This function finds the query if it is valid.
a, b: query range and l, r node range. If query range completely overlap node range, return node else find query in left and right*/
int range_query_helper(vector<int> &st, int a, int b, int l, int r, int root)
{
	if (a<=l && r<=b)
		return st[root];

	// default query value, 0 for sum, inf for min etc.
	// answer for query like 2, 1 where there is no node in ST
	if (b<l || r<a)
		return 0;

	int m = l + (r-l)/2;
	auto left = range_query_helper(st, a, b, l, m, 2*root+1);
	auto right = range_query_helper(st, a, b, m+1, r, 2*root+2);

	// same operation as ST. min for min, OR for OR and + for sum.
	return left + right;
}

/*Function to update the value in tree and arr at ind. Directly update the value to new_value in arr and then update tree*/
void updateValue(vector<int> &tree, vector<int> &arr, int n, int ind, int new_value)
{
	if (ind<0 || ind>n-1)
		return ;

	arr[ind] = new_value;
	updateTree(tree, 0, n-1, ind, new_value, 0);
}

void updateTree(vector<int> &tree, int l, int r, int ind, int new_value, int root)
{
	if (ind<l || r<ind)
		return ;

	if (l==r){
		tree[root] = new_value;
		return ;
	}

	int m = l + (r-l)/2;
	updateTree(tree, l, m, ind, new_value, 2*root+1);
	updateTree(tree, m+1, r, ind, new_value, 2*root+2);

	// operation on RHS same as ST. + for sum, | for OR, & for AND
	tree[root] = tree[2*root+1] + tree[2*root+2];

}

void printST(vector<int> &tree, int n)
{
	for (int i=0;i<n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
}


/*Application:
https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-4
1. Find sum, product, OR, AND,max or min of a range
2. Find LCM or GCD of a range
3. Find number of 0 in a range

*/

