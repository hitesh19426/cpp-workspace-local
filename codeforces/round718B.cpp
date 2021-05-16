#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define inf 1000000000
#define inf_ll 1000000000000000000
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<int, int>
#define vll vector<long long>
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	cin>>t;
	while(t--){
		solve();
		//cout<<endl;
	}
	return 0;
}

void solve(){
	int n, m;
	cin>>n>>m;

	int arr[n][m];
	rep(i, n){
		rep(j, m){
			cin>>arr[i][j];
		}
	}

	rep(i, n){
		sort(arr[i], arr[i]+m);
	}



	int buckets[m][n];
	rep(i, m){
		rep(j, n){
			buckets[i][j]=arr[j][i];
		}
	}

	// rep(i, n){
	// 	rep(j, m){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	// rep(i, m){
	// 	rep(j, n){
	// 		cout<<buckets[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;


	pii min_elements_of_bucket[n];
	rep(i, n){
		min_elements_of_bucket[i]=mp(buckets[0][i], i);
		//cout<<"buckets[i][0]:"<<buckets[0][i]<<endl;
	}
	sort(min_elements_of_bucket, min_elements_of_bucket+n);

	int current_element_of_bucket[n];
	rep(i, n){
		current_element_of_bucket[i]=m-1;
	}

	// cout<<"min_elements_of_bucket"<<endl;
	// rep(i, n){
	// 	cout<<min_elements_of_bucket[i].first<<" "<<min_elements_of_bucket[i].second<<" ";
	// }
	// cout<<endl;
	// rep(i, n){
	// 	cout<<current_element_of_bucket[i]<<" ";
	// }
	// cout<<endl;
	// cout<<endl;
	// cout<<endl;

	int paths[m][n], cur_min_element_index=0, row=0;
	rep(i, m)
	{
		int min_ind=min_elements_of_bucket[cur_min_element_index++].second;
		cout<<"min_index:"<<min_ind<<endl;
		//cout<<"n:"<<n<<endl;
		for (int j=0;j<n;j++){
			cout<<"cur_min_element_index:"<<cur_min_element_index<<endl;
			if (j==min_ind && cur_min_element_index<m){
				paths[i][j] = buckets[0][j];
				cout<<"buckets[j][0]: ";
				cout<<buckets[0][j]<<endl;
			}
			else{
				cout<<"current_element_of_bucket[i]:";
				cout<<current_element_of_bucket[i]<<endl;
				cout<<"buckets[j][current_element_of_bucket[i]]: ";
				cout<< buckets[current_element_of_bucket[i]][j]<<endl;

				paths[i][j] = buckets[current_element_of_bucket[i]][j];
				current_element_of_bucket[i]--;
				cout<<"current_element_of_bucket[i]:";
				cout<<current_element_of_bucket[i]<<" "<<i<<endl;

			}
		}

		cout<<"path: ";
		rep(j, n){
			cout<<paths[i][j]<<" ";		
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
		//cur_min_element_index++;
	}

	cout<<"paths final:";
	rep(i, m){
		rep(j, n){
			cout<<paths[i][j]<<" ";
		}
		cout<<endl;
	}
}

