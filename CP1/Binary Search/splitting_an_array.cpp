#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define nline '\n'
#define inf INT_MAX
#define mod 1000000007
#define mod1 998244353
#define inf_ll LLONG_MAX
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
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


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

// bool check(vll &arr, ll mid, int k)
// {
// 	// count is how many buckets/segments are full, sum is sum of last segment
// 	// wrong answer, for mid = 12, if you put 4 in 8 bucket and 5 in 4 bucket, you get a maximum sum of 12
// 	// but here you are getting a maximum sum of 13. general feeling is that you will try to combine small
// 	//  elements with big elements so overall sum can be balanced, however, here you are grouping elements 
// 	//  value wise (assending/descending)
// 	// long long sum=0, count=0, n=arr.size();
// 	for(int i=0;i<n;i++){
		
// 		if(arr[i]>mid)
// 			return false;
// 		sum += arr[i];

// 		if(sum>mid){
// 			count++;
// 			sum = arr[i];
// 		}

// 	}
// 	count++;

// 	return (count<=k ? true : false);
// }


bool check(vll &arr, ll mid, int k)
{
	int n=arr.size();
	long long sum=0, l=0, r=n-1, count=0;
	while(l<=r){
		
		if(arr[r]>mid)
			return false;

		while(sum+arr[r]<=mid){
			sum += arr[r];
			r--;
		}
		while(sum+arr[l]<=mid){
			sum += arr[l];
			l++;
		}
		
		count++;
		sum=0;
		if(count>k)
			return false;
	}

	if(mid==13){
		print(count);
	}

	return (count<=k ? true : false);
}


void solve(){
	int n, k;
	cin>>n>>k;

	vll arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());

	long long l=0, r=1000'000'000'000'000, ans=-1;
	string ins="inside";
	while(l<=r){
		long long mid=l+(r-l)/2;
		print(l);
		print(r);
		cerr << "before check\n";
		// cerr<<endl;cerr<<endl;

		if(check(arr, mid, k)){
			// print(ins);
			print(mid);

			ans = mid;
			r=mid-1;
			
			// print(mid);
			print(ans);
			// print(r);
			// print(l);
		}
		else{
			l=mid+1;
		}
		print(l);
		print(r);
		cerr<<endl;
	}

	cout<<ans;
}

