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
	ll p, a, b, c;
	cin>>p>>a>>b>>c;

	ull amin=(ull)a*ceil((ld)p/a);
	ull bmin=(ull)b*ceil((ld)p/b);
	ull cmin=(ull)c*ceil((ld)p/c);

	cout<<min(amin-p, min(bmin-p, cmin-p));
}