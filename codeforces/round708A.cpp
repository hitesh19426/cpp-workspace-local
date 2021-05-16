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
bool fre_gre_1(int arr[], int n);

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

bool fre_gre_1(int arr[], int n){
	rep(i, n){
		if (arr[i]>=1)
			return true;
	}
	return false;
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	rep(i, n)	cin>>arr[i];

	int fre[101]={0};
	rep(i, n)	fre[arr[i]]++;

	while (fre_gre_1(fre, 101)){
		rep(i, 101){
			if (fre[i]>=1){
				cout<<i<<" ";
				fre[i]--;
			}
		}
	}
}