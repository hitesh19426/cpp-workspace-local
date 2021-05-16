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
	int arr[]={1, 2, 3, 4, 5, 6};
	do{
		cout<<6<<endl;
		rep (i,  6) cout<<arr[i]<<" ";
		cout<<endl;
	}while (next_permutation(arr, arr+6));

	return 0;
}

void solve(){
	return;
}