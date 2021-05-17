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

void hanoi(int n, int src, int dest, int temp)
{
	if (n==1){
		cout<<src<<" "<<dest<<endl;
		return;
	}

	hanoi(n-1, src, temp, dest);
	cout<<src<<" "<<dest<<endl;
	hanoi(n-1, temp, dest, src);
}

void solve(){
	int n;
	cin>>n;

	cout<< (1<<n) - 1 <<endl;
	hanoi(n, 1, 3, 2);
}

