#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define pb push_back
#define mp make_pair
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


/*----------------------------------------------------------------------------------------------------*/

int binary_search(vector<pii> arr, int l, int r, int x)
{
	if (r<l)
		return -1;

	int m = l+(r-l)/2;
	
	if (arr[m].first == x)
		return m;
	if (arr[m].first < x)
		return binary_search(arr, m+1, r, x);
	return binary_search(arr, l, m-1, x);
}

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int n, x;
    cin>>n>>x;

    vector<pii> arr(n);
    for(int i=0; i<n; i++) {
		cin>>arr[i].first;
		arr[i].second = i;
	}
   
    sort(arr.begin(), arr.end());

    int p1=0, p2=n-1;
    while (p1<p2)
    {
    	if (arr[p1].first+arr[p2].first==x)
    	{
    		cout<<arr[p1].second+1<<" "<<arr[p2].second+1<<endl;
    		return 0;
    	}
    	else if (arr[p1].first+arr[p2].first < x)
    		p1++;
    	else
    		p2--;
    }


    cout<<"IMPOSSIBLE\n";
	return 0;
}

