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
	int n, k;
	cin>>n>>k;

	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int maxs = (k&1 ? k/2+1 : k/2);
	multiset<int> maxset, minset;
	long long maxsum=0, minsum=0;

	for(int i=0; i<maxs; i++){
		maxset.insert(arr[i]);
		maxsum += arr[i];
	}

	for(int i=maxs; i<k; i++){
		if(arr[i] <= *maxset.begin()){
			minset.insert(arr[i]);
			minsum += arr[i];
		}
		else{
			maxsum += arr[i];
			maxsum -= *maxset.begin();
			minsum += *maxset.begin();

			maxset.insert(arr[i]);
			minset.insert(*maxset.begin());
			maxset.erase(maxset.begin());
		}
	}

	for(int i=0; i+k-1<n; i++){
		if(i!=0){
			auto itr = maxset.find(arr[i-1]);
			if(itr == maxset.end()){
				minsum -= arr[i-1];
				minset.erase(minset.find(arr[i-1]));
			}
			else{
				maxsum -= *itr;
				maxset.erase(itr);
				// to maintain size of maxset and not insert into maxset
				// by default in ahead code
				if(!minset.empty()){
					int big = *minset.rbegin();
					maxset.insert(big);
					minset.erase(minset.find(big));

					maxsum += big;
					minsum -= big;
				}
			}

			if((int)maxset.size()<maxs){
				maxsum += arr[i+k-1];
				maxset.insert(arr[i+k-1]);
			}
			else if(arr[i+k-1] <= *maxset.begin()){
				minsum += arr[i+k-1];
				minset.insert(arr[i+k-1]);
			}
			else{
				maxsum += arr[i+k-1];
				minsum += *maxset.begin();
				maxsum -= *maxset.begin();

				maxset.insert(arr[i+k-1]);
				minset.insert(*maxset.begin());
				maxset.erase(maxset.begin());
			}
		}

		long long median = *maxset.begin();
		long long costmax = maxsum - median*maxset.size();
		long long costmin = median*minset.size() - minsum;
		long long cost = costmax + costmin;
		cout << cost << endl;

	}
}
