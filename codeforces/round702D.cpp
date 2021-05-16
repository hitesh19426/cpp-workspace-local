#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
using namespace std;
void solve();

class Node{
	public:
	int val;
	Node *left_node;
	Node *right_node;

	Node(int v){
		val=v;
		left_node=NULL;
		right_node=NULL;
	}
};

Node* buildTree(Node *root, int arr[], int l, int r){
	if (r<l){
		root=NULL;
		//cout<<root->val<<root->left_node<<root->right_node<<endl;
		return root;
	}
	if (r==l){
		root=new Node(arr[l]);
		cout<<"l, r:"<<l<<" "<<r<<endl;
		cout<<root->val<<root->left_node<<root->right_node<<endl;
		return root;
	}

	int max_index=l;
	for (int i=l+1;i<=r;i++){
		if (arr[max_index]<arr[i])
			max_index=i;
	}

	
	root=new Node(arr[max_index]);

	//cout<<arr[max_index];
	cout<<"l, r:"<<l<<" "<<r<<endl;
	cout<<root->val<<root->left_node<<root->right_node<<endl;
	
	buildTree(root->left_node, arr, l, max_index-1);
	buildTree(root->right_node, arr, max_index+1, r);

	return root;
}

// void dfs(Node *root, int depth[], int curr){
// 	if (root==NULL)
// 		return;

// 	// depth[root.val]=curr;
// 	cout<<root->val<<root->left_node<<root->right_node<<endl;
// 	dfs(root->left_node, depth, curr+1);
// 	dfs(root->right_node, depth, curr+1);
// }

int main(int argc, char const *argv[])
{
	/* code */
	int t;
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
	int arr[n];
	rep(i, n)	cin>>arr[i];

	cout<<"inside solve"<<n<<endl;

	Node *root;
	//cout<<root<<endl;
	root=buildTree(root, arr, 0, n-1);
	// cout<<root<<endl;
	cout<<root->val<<root->left_node<<root->right_node<<endl;
	int depth[101]={0};
	// dfs(root, depth, 0);

	// rep(i, n) cout<<depth[arr[i]]<<" ";

}