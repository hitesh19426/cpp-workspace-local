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
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		//cout<<endl;
	}
	return 0;
}

void solve(){
	int n, q;
	cin>>n>>q;
	
	int arr[n];
	rep(i, n)	cin>>arr[i];
	int one=0, zero=0;
	rep(i, n){	
		if (arr[i]==1) 
			one++; 
		else zero++;
	}
	// cout<<zero<<" "<<one<<endl;

	while (q--)
	{
		int query;
		cin>>query;

		if (query==1) {
			int x;
			cin>>x;
			
			if (arr[x-1]==1){
				one--;zero++;
				arr[x-1]=0;
			}
			else{
				zero--;one++;
				arr[x-1]=1;
			}
		}
		else {
			int k;
			cin>>k;
			// k-=1;
			
			if (one<k)
				cout<<0<<endl;
			else
				cout<<1<<endl;
		}
		// cout<<zero<<" "<<one<<endl;
	}
}

