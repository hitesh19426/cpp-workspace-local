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

void merge(vector<int> &arr, int l, int r, int m, long long &ans)
{
	// l..m, m+1...r
	int s1=m-l+1, s2=r-m;
	vector<int> left(s1), right(s2), leftsum(s1+1);

	for(int i=0; i<s1; i++)
		left[i] = arr[i+l];
	for(int i=0; i<s2; i++)
		right[i] = arr[m+1+i];

	leftsum[0] = 0;
	for(int i=1; i<=s1; i++)
		leftsum[i] = leftsum[i-1] + left[i-1];

	int p1=0, p2=0, p=l;
	while(p1<s1 && p2<s2)
	{
		if(left[p1]<=right[p2]){
			arr[p++] = left[p1++];
		}
		else{
			ans += leftsum[s1] - leftsum[p1];
			arr[p++] = right[p2++];
		}
	}

	while(p1<s1)
		arr[p++] = left[p1++];

	while(p2<s2)
		arr[p++] = right[p2++];
}

void mergeSort(vector<int> &arr, int l, int r, long long &ans)
{
	if(r<=l)
		return;

	int mid = l+(r-l)/2;
	mergeSort(arr, l, mid, ans);
	mergeSort(arr, mid+1, r, ans);

	merge(arr, l, r, mid, ans);
}

void solve(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];

	long long ans = 0;
	mergeSort(arr, 0, n-1, ans);
	cout<<ans;
}
