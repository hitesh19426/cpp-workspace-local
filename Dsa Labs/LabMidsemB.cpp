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

	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	vector<int> ans(n);
	fill(ans.begin(), ans.end(), 0);
	stack<pair<int, int>> st;

	for(int i=n-1; i>=0; i--){
		while(!st.empty() && st.top().first < arr[i])
			st.pop();

		if(st.empty())
			ans[i] = 0;
		else
			ans[i] = st.top().second - i;

		st.push({arr[i], i});
	}

	for(int i=0; i<n; i++){
		cout << ans[i] << " ";
	}


	return 0;
}
