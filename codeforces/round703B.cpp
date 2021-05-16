#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
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

	int x[n];
	int y[n];

	rep(i, n){
		cin>>x[i]>>y[i];
	}

	sort(x, x+n);
	sort(y, y+n);

	if (n%2==1){
		cout<<1;
	}
	else{
		ll x_pos=(ll)(x[n/2]-x[n/2-1]+1);
		ll y_pos=(ll)(y[n/2]-y[n/2-1]+1);
		//cout<<x_pos<<" "<<y_pos<<endl;
		cout<<x_pos*y_pos;
	}
}