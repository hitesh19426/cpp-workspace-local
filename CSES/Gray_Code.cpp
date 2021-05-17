#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
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
	int n;
	cin>>n;

	if (n==1){
		cout<<1<<endl<<0<<endl;
		return;
	}

	int arr[(1<<n)][n];
	for (int i=n-1;i>=0;i--)
	{
		int pow = n-i+1;
		int plen = (1<<pow);
		int len = (1<<n);

		print(pow);
		print(plen);
		print(len);
		cerr << endl;

		int k=0;
		print(i);
		while (k<len)
		{
			for (int j=0;j<plen/4 && k<len;j++){
				print(k);
				arr[k++][i] = 0;
				print(arr[k-1][i]);
			}
			for (int j=0;j<plen/2 && k<len;j++){
				print(k);
				arr[k++][i] = 1;
				print(arr[k-1][i]);
			}
			for (int j=0;j<plen/4 && k<len;j++){
				print(k);
				arr[k++][i] = 0;
				print(arr[k-1][i]);
			}
			cerr<<endl;
		}
	}

	for (int i=0;i<(1<<n);i++)
	{
		for (int j=0;j<n;j++)
			cout<<arr[i][j];
		cout<<endl;
	}

}

