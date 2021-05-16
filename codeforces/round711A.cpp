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

bool gcdSum(ll n)
{
	ll n_copy=n;
	ll sum_of_digit=0;
	while (n_copy!=0)
	{
		// cout<<n_copy<<" "<<sum_of_digit<<endl;
		sum_of_digit += n_copy%10;
		n_copy = n_copy/10;
	}

	if (gcd(n, sum_of_digit)>1)
		return true;
	return false;
}

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
	ull n;
	cin>>n;
	while (!gcdSum(n)){
		// cout<<n;
		n++;
	}
	// cout<<endl;
	cout<<n;
}