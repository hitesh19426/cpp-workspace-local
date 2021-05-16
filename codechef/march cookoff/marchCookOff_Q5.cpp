#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n, m, k;
	cin>>n>>m>>k;

	int min_mn=min(n, m);
	int max_mn=max(n, m);
	ll ans=0;
	for (int i=1;i<=min_mn;i+=2){
		ans = ans^((ll)k+i+1);
	}
	if (min(n, m)%2==1){
		for (int i=0;i<max_mn-min_mn;i++){
			ans = ans^((ll)k+min_mn+i+2);
		}
		
	}
	for (int i=0;i<min(n, m)-1;i+=2){
		ans = ans^((ll)k+n+m-i);
	}

	cout<<ans;

}