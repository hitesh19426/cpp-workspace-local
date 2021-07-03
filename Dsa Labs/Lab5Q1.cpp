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
	string s;
	cin>>s;

	stack<char> st;
	for(char c:s){
		if(c=='(' || c=='{'){
			st.push(c);
		}
		else if(c==')'){
			if(st.empty() || st.top()!='('){
				cout<<0;
				return ;
			}
			else{
				st.pop();
			}
		}
		else{
			if(st.empty() || st.top()!='{'){
				cout<<0;
				return ;
			}
			else{
				st.pop();
			}
		}
	}

	cout << (st.empty() ? 1 : 0);
}
