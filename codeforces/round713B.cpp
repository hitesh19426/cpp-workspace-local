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
		//cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	char arr[n][n];
	pii p1, p2;
	int count=0;
	rep(i, n){
		rep(j, n){
			cin>>arr[i][j];
			if (arr[i][j]=='*')
			{
				if (count==0){
					p1=make_pair(i, j);
					count++;
				}
				else if (count==1){
					p2=make_pair(i, j);
					count++;
				}
			}

		}
	}

	if (p1.first==p2.first){
		if (p1.first==0){
			arr[1][p1.second]='*';
			arr[1][p2.second]='*';
		}
		else{
			arr[0][p1.second]='*';
			arr[0][p2.second]='*';
		}
	}
	else if (p1.second==p2.second){
		if (p1.second==0){
			arr[p1.first][1]='*';
			arr[p2.first][1]='*';
		}
		else{
			arr[p1.first][0]='*';
			arr[p2.first][0]='*';
		}
	}
	else{
		arr[p1.first][p2.second]='*';
		arr[p2.first][p1.second]='*';
	}



	rep(i, n){
		rep(j, n){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}

