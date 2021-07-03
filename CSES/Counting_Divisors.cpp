#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t=1;
	cin>>t;

	while(t--){
		solve();
		cout<<endl;
	}

	return 0;
}

void solve()
{
	int x;
	cin>>x;

	int count = 0;
	for(int i=1; i*i<=x; i++){
		if(x%i==0){
			if(x/i == i)
				count++;
			else
				count += 2;
		}
	}

	cout<<count;
}
