#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
using namespace std;
void solve();
bool isPalindrome(string s);

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
	string s;
	cin>>s;

	if ( !isPalindrome(s+'a') ){
		cout<<"YES\n";
		cout<<s+'a';
	}
	else if (!isPalindrome('a'+s)){
		cout<<"YES\n";
		cout<<'a'+s;
	}
	else{
		cout<<"NO";
	}
}

bool isPalindrome(string s){
	//cout<<"string: "<<s<<endl;
	int n=s.length();
	rep(i, s.length()/2){
		if (s[i]!=s[n-i-1])
			return false;
	}
	return true;
}

