#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define inf 1000000000
#define inf_ll 1000000000000000000
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<int, int>
#define vll vector<long long>
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
using namespace std;
void solve();


/* The functions required for segment tree construction, range query and update function*/
ll* buildST(ll arr[], int n);
// int fillST(ll arr[], ll *tree, int l, int r, int root);
ll range_query(ll st[], int n, int a, int b);
ll range_query_helper(ll st[], int a, int b, int l, int r, int root);
void updateValue(ll *tree, ll arr[], int n, int ind, ll new_value);
void updateTree(ll *tree, int l, int r, int ind, ll new_value, int root);
void fillST2(ll arr[], ll *tree, int l, int r, int root);
// void printST(int *tree, int n);
/* The functions required for segment tree construction, range query and update function*/


int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	cin>>t;
	while(t--){
		solve();
		//cout<<endl;
	}
	return 0;
}

void solve(){
	int n, q;
	cin>>n>>q;

	ll arr[n];
	rep(i, n) cin>>arr[i];

	ll *tree=buildST(arr, n);
	cout<<range_query(tree, n, 0, n-1)<<endl;

	while(q--){
		ll x, v;
		cin>>x>>v;
		x--;

		updateValue(tree, arr, n, x, v);
		cout<<range_query(tree, n, 0, n-1)<<endl;
	}


}






/*This ST is for sum query.*/

/*
The function which build the segement tree.
Note: Make sure to create pointer of ll if answer can go to ll and change type of fillST too.
*/
ll* buildST(ll arr[], int n)
{
	int h = (int) ceil(log2(n));

	int size=(int) pow(2, h+1)-1;

	ll *tree=new ll[size];

	fillST2(arr, tree, 0, n-1, 0);

	return tree;
}

/*
This is the function that fills the values in the segment tree.
Note: Make sure type of function is ll if answer can go to ll.
*/
int fillST(int arr[], int *tree, int l, int r, int root)
{
	if (l==r){
		tree[root]=arr[l];
		return tree[root];
	}

	int m=l+(r-l)/2;

	int x = fillST(arr, tree, l, m, 2*root+1);
	int y = fillST(arr, tree, m+1, r, 2*root+2);

/*
This is basically the function of the ST. If you want min of elements, tree[root] = min(x, y)
If you want pro of elements, tree[root] = x*y. 	If you want AND/OR, do that. 
*/
	tree[root] = x + y;
	return tree[root];
}

void fillST2(ll arr[], ll *tree, int l, int r, int root)
{
	if (l==r){
		tree[root] = arr[l];
		return ; 
	}

	int m = l+(r-l)/2;

	fillST2(arr, tree, l, m, 2*root+1);
	fillST2(arr, tree, m+1, r, 2*root+2);

	tree[root] = tree[2*root+1] | tree[ 2*root+2];
}


/*This function return query in the range from a to b include*/
ll range_query(ll st[], int n, int a, int b)
{
	// wrong query basically
	if (b<0 || a>n-1 || b<a){
		return -1;
	}

	return range_query_helper(st, a, b, 0, n-1, 0);
}

/*This function finds the query if it is valid.
a, b: query range and l, r node range. If query range completely overlap node range, return node else find query in left and right*/
ll range_query_helper(ll st[], int a, int b, int l, int r, int root)
{
	if (a<=l && r<=b)
		return st[root];

	// default query value, 0 for sum, inf for min etc.
	// answer for query like 2, 1 where there is no node in ST
	if (b<l || r<a)
		return 0;

	int m = l + (r-l)/2;
	ll left = range_query_helper(st, a, b, l, m, 2*root+1);
	ll right = range_query_helper(st, a, b, m+1, r, 2*root+2);

	// same operation as ST. min for min, OR for OR and + for sum.
	return left | right;
}

/*Function to update the value in tree and arr at ind. Directly update the value to new_value in arr and then update tree*/
void updateValue(ll *tree, ll arr[], int n, int ind, ll new_value)
{
	if (ind<0 || ind>n-1)
		return ;

	arr[ind] = new_value;
	updateTree(tree, 0, n-1, ind, new_value, 0);
}

void updateTree(ll *tree, int l, int r, int ind, ll new_value, int root)
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
	tree[root] = tree[2*root+1] | tree[2*root+2];

}

void printST(int *tree, int n)
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

