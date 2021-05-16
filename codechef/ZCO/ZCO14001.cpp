#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
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
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n, h;
	cin>>n>>h;
	int arr[n];
	rep(i, n)	cin>>arr[i];

	int pos=0;
	int boxes=0;

	std::vector<int> v;
	while (true){
		int x;
		cin>>x;
		v.push_back(x);

		if (x==0)
			break;
	}

	rep(i, v.size()){
		if (v[i]==1){
			if (pos!=0)
				pos--;
		}
		else if (v[i]==2){
			if (pos!=n-1)
				pos++;
		}
		else if (v[i]==3){
			if (boxes==0 && arr[pos]>0){
				boxes=1;
				arr[pos]--;
			}
		}
		else if (v[i]==4){
			if (boxes==1 && arr[pos]+1<=h){
				boxes=0;
				arr[pos]++;
			}
		}
		else{
			rep(i, n)	cout<<arr[i]<<" ";
			return;
		}
	}
}