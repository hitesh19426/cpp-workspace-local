#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define inf 1000000000
#define inf_ll 1000000000000000000
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<int, int>
#define vll vector<long long>
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
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
	ull n;
	cin>>n;

	ull max_num=205000000000000000;
	ull cur_num=max_num;
	ull n_copy=n;

	if (n<2050)
	{
		cout<<-1;
		return ;
	}

	int count=0;
	while (cur_num>=2050){
		if (n_copy>=cur_num){
			n_copy -= cur_num;
			count++;
		}
		else{
			cur_num /= 10;	
		}
	}

	if (n_copy==0){
		cout<<count;
	}
	else{
		cout<<-1;
	}
}

