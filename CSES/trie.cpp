#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define ull unsigned long long
#define nline '\n'
#define INF INT_MAX
#define mod1 998244353
#define INFLL LLONG_MAX
#define PI 3.141592653589793238462

#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vpii vector<pair<int, int>>
#define pll pair<long long, long long>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

#ifndef ONLINE_JUDGE
#define print(x) cerr<< #x << " = "; _print(x); cerr<<endl;
#else
#define print(x)
#endif
void _print(ll t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(string t) {cerr << t;}
template <class T, size_t N> void _print(T (&arr)[N]) {cerr << "[ "; for(T v:arr) { cerr<< (v) <<" "; } cerr<<"]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//----------------------------------------------------------------------------------------------------//

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

struct trieNode
{
	trieNode *children[26];
	bool endOfWord;

	trieNode(){
		for(int i=0; i<26; i++)
			children[i] = nullptr;
		endOfWord = false;
	}
};

void insert(trieNode *root, string key)
{
	trieNode *ptr = root;
	for(int i=0; i<(int)key.size(); i++){
		int ind = key[i] - 'a';

		if(ptr->children[ind]==nullptr){
			ptr->children[ind] = new trieNode();
		}

		ptr = ptr->children[ind];
	}

	ptr->endOfWord = true;

}

bool search(trieNode *root, string str)
{
	trieNode *ptr = root;
	int i, n=str.size();
	for( i=0; i<n; i++){
		int ind = str[i] - 'a';
		if(ptr->children[ind] == nullptr)
			return false;

		ptr = ptr->children[ind];
	}

	return ptr->endOfWord;
}

void solve(){
	vector<string> arr{"the", "a", "there", "answer", "any", "by", "bye", "their"};

	trieNode *root = new trieNode();

	for(string str:arr)
		insert(root, str);

	search(root, "there") ? cout << "YES\n" : cout << "NO\n";
search(root, "these") ? cout << "YES\n" : cout << "NO\n";
}
