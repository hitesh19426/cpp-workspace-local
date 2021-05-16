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

int no_of_digit(ll x){
	int count=0;
	while(x>0){
		x/=10;
		count++;
	}
	return count;
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
	int a, b, c;
	cin>>a>>b>>c;

	ll c_num=7;
	while (no_of_digit(c_num)<c){
		c_num*=7;
	}

	ll a_num=c_num;
	ll b_num=c_num;

	while (no_of_digit(a_num)<a){
		a_num*=2;
	}
	while (no_of_digit(b_num)<b){
		b_num*=3;
	}

	cout<<a_num<<" "<<b_num;
	
}

