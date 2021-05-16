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
	int n, l ,r, s;
	cin>>n>>l>>r>>s;

	int size=r-l+1;
	if (s<(size*(size+1))/2){
		cout<<-1;
		return;
	}
	int max=(size*(2*n-size+1))/2;
	if (s>max){
		cout<<-1;
		return;
	}

	int cur=n;
	std::vector<int> v;
	while (s>0){
		if (s>=cur){
			s-=cur;
			v.push_back(cur);
		}
		else{
			cur--;
		}
	}

	int arr[n];
	for (int i=l-1;i<)


}

