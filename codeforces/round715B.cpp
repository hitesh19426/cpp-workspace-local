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
#define pb push_back
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

	string s;
	cin>>s;

	int t_count=0, m_count=0;
	rep(i, n){
		if (s[i]=='M')
			m_count++;
		else t_count++;
	}

	if (2*m_count!=t_count){
		cout<<"NO";
		return;
	}

	vector<int> m;
	vector<int> t;
	rep(i, n){
		if (s[i]=='M')
			m.push_back(i);
		else t.push_back(i);
	}

	// int count=0;
	rep(i, m_count){
		if (t[i]<m[i] && m[i]<t[i+m_count]){
			continue;
		}
		else
		{
			cout<<"NO";
			return;
		}
	}

	cout<<"YES";

}

