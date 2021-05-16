#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'



#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>




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

pii sum_of_two_value(pll arr[], int l, int r, ll x)
{
	int p1=l, p2=r;
	while (p1<p2)
	{
		if (arr[p1].first + arr[p2].first == x){
			return mp(p1, p2);
		}

		if (arr[p1].first + arr[p2].first < x){
			p1++;
		}
		else{
			p2--;
		}
	}

	return mp(-1, -1);
}

void solve(){
	ll n, x;
	cin>>n>>x;

	pll arr[n];
	rep(i, n){
		cin>>arr[i].first;
		arr[i].second = i+1;
	}

	sort(arr, arr+n);

	// rep(i, n){
	// 	cout<<arr[i].first<<" "<<arr[i].second<<endl;
	// }

	for (int i=0;i<n-2;i++)
	{
		auto pa = sum_of_two_value(arr, i+1, n-1, x-arr[i].first);

		if (pa.first !=-1 && pa.second!=-1)
		{
			cout<<arr[i].second<<" "<<arr[pa.first].second<<" "<<arr[pa.second].second;
			return;
		}

	}

	cout<<"IMPOSSIBLE";
}

