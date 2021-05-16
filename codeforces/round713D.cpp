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

	ll b[n+2];
	rep(i, n+2)	cin>>b[i];

	sort(b, b+n+2);

	ll dp[n+2];
	dp[0]=b[0];
	reps(i, 1, n+2){
		dp[i]=dp[i-1]+b[i];
	}

	// rep(i, n+2){
	// 	cout<<b[i]<<" ";
	// }
	// cout<<endl;

	// rep(i, n+2){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	// cout<<b[n+1]<<endl;
	// cout<<dp[n]<<endl;

	if (b[n]==dp[n-1]){
		// cout<<"this is true"<<endl;
		rep(i, n){
			cout<<b[i]<<" ";
		}
		return;
	}
	else{
		ll var=dp[n]-b[n+1];
		// cout<<var<<endl;
		int ind=-1;
		rep(i, n+1){
			if (b[i]==var){
				ind=i;
				break;
			}
		}
		// cout<<"ind:"<<ind<<endl;
		if (ind==-1){
			cout<<-1;
			return;
		}
		rep(i, n+1){
			if (i==ind)
				continue;
			else
				cout<<b[i]<<" ";
		}
	}


}

