#include <bits/stdc++.h>
using namespace std;
void solve();

/*----------------------------------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

long long mergeInversions(vector<int> &nums, int l, int r, int m)
{
	// nums[l...m m+1...r]
	int s1=m-l+1, s2=r-m;
	int left[s1];
	int right[s2];

	for(int i=0;i<s1;i++)
	   left[i] = nums[l+i];

	for(int i=0;i<s2;i++)
	   right[i] = nums[m+1+i];

	int p1=0, p2=0, p=l; 
	long long count=0;
	while(p1<s1 && p2<s2)
	{
	   if(left[p1]<=right[p2]) {
	       nums[p++] = left[p1++];
	   }
	   else {
	       count += s1-p1;
	       nums[p++] = right[p2++];
	   }
	}

	while(p1<s1)
	   nums[p++] = left[p1++];

	while(p2<s2)
	   nums[p++] = right[p2++];

	return count;
}

long long globalInversion(vector<int> &nums, int l, int r)
{
	if(r<=l)
   	return 0;
  
	int m = l+(r-l)/2;
	long long left = globalInversion(nums, l, m);
	long long right = globalInversion(nums, m+1, r);
	long long merge = mergeInversions(nums, l, r, m);
  
	return left+right+merge;
}

void solve(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	long long count=globalInversion(arr, 0, n-1);
	int ans = count%26;
	cout<<char('a'+ans);	
}
