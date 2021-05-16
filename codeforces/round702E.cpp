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

struct player
{
	int id;
	int points;
	ll sum;
	bool result=false;
};

bool sortbypoints(const player &a, const player &b){
	return a.points<b.points;
}

bool sortbyid(const player &a, const player &b){
	return a.id<b.id;
}

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

	player players[n];
	rep(a, n){
		cin>>players[a].points;
		players[a].id=a+1;
	}

	sort(players, players+n, sortbypoints);
	players[0].sum = players[0].points;
	reps(i, 1, n){
		players[i].sum = players[i-1].sum + players[i].points;
	}

	players[n-1].result=true;
	int count=1;
	for (int i=n-2;i>=0;i--){
		if (players[i].sum>=players[i+1].points){
			players[i].result=true;
			count++;
		}
		else
			break;
	}


	sort(players, players+n, sortbyid);
	// rep(i, n){
	// 	cout<<players[i].id<<" "<<players[i].points<<" "<<players[i].sum<<" "<<players[i].result<<endl;
	// }

	cout<<count<<endl;
	rep(i ,n){
		if (players[i].result)
			cout<<players[i].id<<" ";
	}
	count<<endl;


}

