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
	int q;
	cin>>q;

	stack<int> st;
	stack<int> maxst;

	while(q--){
		int query;
		cin>>query;

		if(query==1){
			int x;
			cin>>x;

			st.push(x);
			maxst.empty() ?maxst.push(x) : maxst.push(max(maxst.top(), x));
		}
		else if(query==2){
			if(st.empty()){
				cout<<-1<<endl;
			}
			else{
				cout<<st.top()<<endl;
				st.pop();
				maxst.pop();
			}
		}
		else if(query==3){
			cout << (st.empty() ? -1 : st.top()) << endl;
		}
		else{
			cout << (maxst.empty() ? -1 : maxst.top()) << endl;
		}
	}
}
