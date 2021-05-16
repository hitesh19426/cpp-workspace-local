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
	// cin>>t;
	while(t--){
		solve();
		// cout<<endl;
	}
	return 0;
}

void solve(){
	int n, q;
	cin>>n>>q;

	int arr[n];
	rep(i, n){
		cin>>arr[i];
	}

	// rep(i, n){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	int highest[51]={0};
	rep(i, n){
		if (highest[arr[i]]==0)
			highest[arr[i]]=i+1;

		// cout<<arr[i]<<endl;
		// cout<<highest[arr[i]]<<endl;
	}

	// rep(i, 5){
	// 	cout<<highest[i]<<" ";
	// }
	// cout<<endl;

	int query[q];
	rep(i, q){
		cin>>query[i];
	}
	rep(i, q){
		int x=highest[query[i]];
		cout<<x<<endl;

		rep(i, 51){
			if (highest[i]<x && highest[i]>0){
				highest[i]++;
			}
		}
		highest[query[i]]=1;

		// rep(i, 5){
		// 	cout<<highest[i]<<" ";
		// }
		// cout<<endl;
	}
	
	
}

