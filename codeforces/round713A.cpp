#include<bits/stdc++.h>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define endl '\n'
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
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

	map<int, int> umap;
	rep(i, n){
		if (umap.find(arr[i])==umap.end())
			umap[arr[i]]=1;
		else
			umap[arr[i]]++;
	}

	int x;
	for (auto itr=umap.begin();itr!=umap.end();itr++){
		if (itr->second==1)
			x=itr->first;
	}

	rep(i, n){
		if (arr[i]==x){
			cout<<i+1;
			return;
		}
	}

}

