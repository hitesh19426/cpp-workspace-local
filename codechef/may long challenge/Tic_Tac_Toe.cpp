#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

#define pb push_back
#define mp make_pair
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int solve();

#ifndef ONLINE_JUDGE
#define print(x) cerr<< #x << " = "; _print(x); cerr<<endl;
#else
#define print(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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
		int x= solve();
		print(x);
		cerr << endl;
		cout<<x;
		cout<<endl;
	}
	return 0;
}

int win(string s[], char x)
{
	int count = 0;
	for (int i=0;i<3;i++){
		if (s[i][0] == s[i][1] && s[i][1]==s[i][2] && s[i][2]==x)
			count++;
	}

	for (int i=0;i<3;i++){
		if (s[0][i] == s[1][i] && s[1][i]==s[2][i] && s[2][i]==x)
			count++;
	}

	if (s[0][0] == s[1][1] && s[1][1]==s[2][2] && s[2][2]==x)
		count++;

	if (s[0][2] == s[1][1] && s[1][1]==s[2][0] && s[2][0]==x)
		count++;

	return count;
}

int solve()
{
	string s[3];
	cin>>s[0]>>s[1]>>s[2];

	int count_x=0, count_o=0, count_=0, A=0;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (s[i][j] == 'X')
				count_x++;
			if (s[i][j] == 'O')
				count_o++;
		}
	}
	A = count_o + count_x;
	count_ = 9 - A;
	

	int win_x = win(s, 'X');
	int win_o = win(s, 'O');

	print(win_x);
	print(win_o);
	print(count_x);
	print(count_o);
	print(count_);
	print(A);

	if (A%2==0){
		if ( count_x!=A/2 || count_o!=A/2)
			return 3;
	}
	else{
		if ( count_x!=A/2+1 || count_o!=A/2)
			return 3;
	}
	
	if (win_x && win_o)
		return 3;
	
	if (win_o && count_o!=count_x)
		return 3;

	if (win_x && count_x!=count_o+1)
		return 3;

	if (count_ == 0)
		return 1;

	if (win_x || win_o)
		return 1;

	return 2;

}

/*

2
3
1
1
1
3
1
2




*/
