#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n;
	cin>>n;

	list<int> lst;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		lst.push_back(x);
	}

	int count = 0;
	auto itr = ++lst.begin();
	while(itr != lst.end()){

		auto prev = --itr;
		++itr;

		if( *(prev) < *(itr)){
			itr++;
		}
		else{
			lst.push_front(*(itr));
			lst.erase(itr);
			count++;
			itr = ++lst.begin();
		}
	}

	cout << count;
}
