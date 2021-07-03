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


	long long factorial[1000001];
	factorial[0] = 1;
	for(int i=1; i<1000001; i++)
		factorial[i] = factorial[i-1]*i % mod;

	string s;
	cin>>s;

	long long arr[26]={0};
	for(char c:s){
		arr[c-'a']++;
	}

	long long dem = 1;
	for(int i=0; i<26; i++){
		dem = (dem*factorial[arr[i]])%mod;
	}
	// print(dem);

	long long inverse = 1, n=mod-2;	// pow(dem, p-2)
	while(n>0){
		if(n&1)
			inverse = (inverse*dem)%mod;
		dem = (dem*dem)%mod;
		n >>= 1;
	}

	long long ans = ( (factorial[(int)s.size()]%mod) * (inverse%mod) )%mod;

	cout<<ans<<endl;
	return 0;
}
