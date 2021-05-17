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
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	if (n%4==1 || n%4==2)
	{
		cout<<"NO";
		return;
	}

	cout<<"YES\n";
	if (n%4==0){
		cout<<n/2<<endl;
		int i;
		for (i=1;i<=n/4;i++){
			cout<<i<<" "<<n-i+1<<" ";
		}
		cout<<endl;
		cout<<n/2<<endl;
		for (;i<=n/2;i++){
			cout<<i<<" "<<n-i+1<<" ";
		}
		return;
	}

	cout<<n/2+1<<endl;
	int i;
	for (i=1;i<=n/4+1;i++)
		cout<<i<<" "<<n-i<<" ";
	cout<<endl;
	cout<<n/2<<endl;
	for (;i<=n/2;i++)
		cout<<i<<" "<<n-i<<" ";
	cout<<n;

}

