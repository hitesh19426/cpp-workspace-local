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

	int arr[n];
	rep(i, n)	cin>>arr[i];
	sort(arr, arr+n);
	
	std::vector<int> a;
	std::vector<int> b;

	a.push_back(arr[0]);
	reps(i, 1, n){
		if (arr[i]!=a[a.size()-1])
			a.push_back(arr[i]);
		else if (b.size()==0)
			b.push_back(arr[i]);
		else if (b.size()>0 && arr[i]!=b[b.size()-1])
			b.push_back(arr[i]);
	}

	int mex_a=0;
	int mex_b=0;
	rep(i, a.size()){
		if (a[i]==i){
			mex_a++;
			continue;
		}
		else{
			break;
		}
	}
	rep(i, b.size()){
		if (b[i]==i){
			mex_b++;
			continue;
		}
		else{
			break;
		}
	}

	cout<<mex_a+mex_b;
}

