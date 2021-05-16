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
	int n, k1, k2, w, b;
	cin>>n>>k1>>k2>>w>>b;

	int white_max=min(k1, k2) + (max(k1, k2)-min(k1, k2))/2;
	int black_max=n-max(k1, k2) + (max(k1, k2)-min(k1, k2))/2;

	if (white_max>=w && black_max>=b)
		cout<<"YES";
	else cout<<"NO";
}