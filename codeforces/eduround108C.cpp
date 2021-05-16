#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define inf 1000000000
#define nline '\n'
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462
#define pb push_back
#define mp make_pair

#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) cout<< #x << " = " << x << endl;

void solve();
vll sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*----------------------------------------------------------------------------------------------------*/

#define N 200000 + 5

struct Node
{
	int university=-1;
	std::vector<ll> skills;
	std::vector<ll> sum;
	int size=0;
};

bool sortysize(const Node &a, const Node &b)
{
	return a.size < b.size ;
}


int first_greater(Node arr[], int n, int x, int l, int r)
{
	if (r<l)
		return n;

	int mid = l + (r-l)/2;
	int ans=n;
	if (arr[mid].size < x)
	{
		ans = first_greater(arr, n, x, mid+1, r);
	}
	else
	{
		ans = mid;
		ans = min(ans, first_greater(arr, n, x, l, mid-1));
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
	
	// print(inf);
	int t=1;
	cin>>t;
	// print(t);

	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}



void solve(){
	int n;
	cin>>n;

	int uni[n];
	for (int i=0;i<n;i++){
		cin>>uni[i];
		// print(uni[i]);
	}
	
	struct Node arr[n+1];
	for (int i=0;i<n;i++){
		int x;
		cin>>x;

		// print(x);
		arr[uni[i]].university = uni[i];
		arr[uni[i]].skills.pb(x);
		arr[uni[i]].size++;
	}

	// rep(i, n+1){
	// 	if (arr[i].size!=0){
			
	// 		print(arr[i].university);
	// 		print(arr[i].size);
	// 		foreach(arr[i].skills)
	// 			cout<<*itr<<" ";
	// 		cout<<endl;
	// 	}
	// }

	rep (i, n+1){
		sort(arr[i].skills.begin(), arr[i].skills.end(), greater<ll>());

		ll sumj=0;
		for (int j=0;j<arr[i].size;j++){
			sumj += arr[i].skills[j];
			arr[i].sum.pb(sumj);
		}
	}

	sort(arr, arr+n+1, sortysize);

	rep(i, n+1){
		if (arr[i].size==0){
			// print(i);
			print(arr[i].size);
		}
		if (arr[i].size!=0){
			cout<<nline;
			// print(i);
			print(arr[i].size);
			// print(arr[i].university);
			
			// foreach(itr, arr[i].skills)
			// 	cout<<*itr<<" ";
			// cout<<endl;
			// foreach(itr, arr[i].sum)
			// 	cout<<*itr<<" ";
			// cout<<endl;
		}
	}
	cout<<nline;

	
	for (int k=1;k<=n;k++)
	{
		// cout<<nline;
		ll sum_final=0;
		
		int ind=first_greater(arr, n+1, k, 0, n);
		// print(ind);
		// print(arr[ind].size);

		for (int j=ind;j<n+1;j++){
			sum_final += arr[j].sum[k*(arr[j].size/k)-1];
		}

		cout<<sum_final<<" ";
	}

	
}

