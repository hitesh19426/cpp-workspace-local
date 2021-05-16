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
	int a, b;
	cin>>a>>b;

	string s;
	cin>>s;

	int n=a+b;
	rep(i, n/2)
	{
		if (s[i]=='0'){
			if (s[n-1-i]=='0'){
				continue;
			}
			else if (s[n-1-i]=='1'){
				cout<<-1;
				return;
			}
			else{
				if (a==0){
					cout<<-1;
					return;
				}
				else{
					s[n-i-1]='0';
				}
			}
		}
		else if (s[i]=='1'){
			if (s[n-1-i]=='0'){
				cout<<-1;
				return;
			}
			else if (s[n-1-i]=='1'){
				continue;
			}
			else{
				if (b==0){
					cout<<-1;
					return;
				}
				else{
					s[n-i-1]='1';
				}
			}
		}
		else{
			if (s[n-1-i]=='0'){
				if (a==0){
					cout<<-1;
					return;
				}
				else{
					s[i]='0';
				}
			}
			else if (s[n-1-i]=='1'){
				if (b==0){
					cout<<-1;
					return;
				}
				else{
					s[i]='1';
				}
			}
			else{
				continue;
			}
		}
	}

	int question=0;
	rep(i, n){
		if (s[i]=='0')
			a--;
		if (s[i]=='1')
			b--;
		if (s[i]=='?')
			question++;
	}

	if (a<0 || b<0){
		cout<<-1;
		return;
	}

	rep(i, n/2)
	{
		if (s[i]=='?'){
			if (a>0){
				s[i]='0';
				s[n-i-1]='0';
				a-=2;
				question-=2;
			}
			else if(b>0){
				s[i]='1';
				s[n-i-1]='1';
				b-=2;
				question-=2;
			}
		}
	}

	if (a<0 || b<0){
		cout<<-1;
		return;
	}

	if (question==0 && a==0 && b==0){
		cout<<s;
		return;
	}

	if (question==1){
		if (a>0){
			s[n/2]='0';
			a--;
		}
		else if (b>0){
			s[n/2]='1';
			b--;
		}
	}

	if (a!=0 || b!=0){
		cout<<-1;
		return;
	}

	cout<<s;

}

