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
	//cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	int b[n];
	int d[n];

	rep(i, n) {
		cin>>b[i]>>d[i];
	}

	sort(b, b+n);
	sort(d, d+n);

	// rep(i, n) {
	// 	cout<<b[i]<<" ";
	// }
	// cout<<endl;
	// rep(i, n) {
	// 	cout<<d[i]<<" ";
	// }
	// cout<<endl;

	int arrived=1, max_guests=1, time=b[0];
	int p1=1, p2=0;

	while (p1<n && p2<n) {
		// cout<<b[p1]<<" "<<d[p2]<<endl;
		if (b[p1]<d[p2]) {
			arrived++;
			if (arrived>max_guests) {
				max_guests=arrived;
				time = b[p1];
			}
			p1++;
		}
		else if (b[p1]==d[p2]){
			p1++;
			p2++;
		}
		else {
			arrived--;
			p2++;
		}
		// cout<<"counts:";
		// cout<<arrived<<" "<<max_guests<<endl;
	}

	cout<<time<<" "<<max_guests;
}
