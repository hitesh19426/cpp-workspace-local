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
#define foreach(v) for (auto itr=v.begin();itr!=v.end();itr++)
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
	rep(i, n) cin>>arr[i];

	int b[n], sum=0;
	rep(i, n) b[i]=-101;
	std::vector<bool> vis(n, false);

	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (sum + arr[j]!=0 && vis[j]==false)
			{
				b[i] = arr[j];
				vis[j]=true;
				sum += b[i];
				break;
			}
		}
		if (b[i]==-101){
			cout<<"NO";
			return;
		}
	}

	cout<<"YES\n";
	rep(i, n){
		cout<<b[i]<<" ";
	}

}
