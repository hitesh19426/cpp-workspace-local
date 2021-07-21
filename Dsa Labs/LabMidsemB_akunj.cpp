#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	int ans[n];
	fill(ans, ans + n, 0);
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
