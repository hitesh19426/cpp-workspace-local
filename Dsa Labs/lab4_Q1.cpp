#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
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

	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	int sum=0;
	for(int i=1; i<n; i++){
		int j=i;
		while(j>0 && arr[j]<arr[j-1]){
			sum += arr[j-1];
			swap(arr[j], arr[j-1]);
			j--;
		}
	}

	cout<<sum;
}
