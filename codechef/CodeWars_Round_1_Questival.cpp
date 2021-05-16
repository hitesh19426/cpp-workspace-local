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

bool sortbyend(const pii& a, const pii &b){
	return a.second<b.second;
}

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

void solve(){
	int n;
	cin>>n;

	pii arr[n];
	rep(i, n){
		cin>>arr[i].first>>arr[i].second;
	}

	sort(arr, arr+n, sortbyend);

	// int last_start=arr[0].first;
	int last_end=arr[0].second;
	int count=1;
	for (int i=1;i<n;i++){
		if (arr[i].first>=last_end){
			last_end = arr[i].second;
			count++;
		}
	}

	cout<<count;
}

