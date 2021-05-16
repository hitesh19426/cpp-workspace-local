#include<bits/stdc++.h>
#define loops(i, a, b) for(int i=a; i < b; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define vll vector<ll>;
#define vpll vector<pll>;
#define inf_ll 1000000000000000000
#define inf 1000000000
#define endl '\n'
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define foreach(v) for (auto itr=v.begin();itr!=v.end();itr++) //use *itr for getting the element
#define print(x) cout<< #x << "=" << x << endl;
using namespace std;
const ll MOD = 1e9 + 7;
ll powerLL(ll x, ll n);

int first_greater(int arr[], int n, int x, int l, int r)
{
    if (r<l)
        return n;

    int mid = l + (r-l)/2;
    int ans=n;
    if (arr[mid] < x)
    {
        ans = first_greater(arr, n, x, mid+1, r);
    }
    else
    {
        ans = mid;
        ans = min(ans, first_greater(arr, n, x, l, mid-1));
    }
    return ans;
}

void solve(){

    int n, l, r;
    cin>>n>>l>>r;

    int left[n+1];
    int right[n+1];

    memset(left, 0, n+1);
    memset(right, 0, n+1);

    loops(i, 0, l) {
        int x;
        cin>>x;
        left[x]++;
        //cin>>left[i];
    }
    loops(i, 0, r) {
        int x;
        cin>>x;
        right[x]++;
    }


    loops(i, 0, n+1) {
        if(left[i] > 0  && right[i] > 0) {
            left[i] -= min(left[i], right[i]);
            right[i] -= min(left[i], right[i]);
        }
    }

    sort(left, left+n+1);
    sort(right, right+n+1);
    int firstGretL = first_greater(left, n+1, 1, 0, n);
    int firstGretR = first_greater(right, n+1, 1, 0, n);

    for (int i=firstGretL;i<=n;i++)
        cout<<left[i]<<" ";
    cout<<endl;

    for (int i=firstGretR;i<=n;i++)
        cout<<right[i]<<" ";
    cout<<endl;

    // ll cost = 0;
    // while(firstGretL <= n && firstGretR <= n) {
    //     if(left[firstGretL] < right[firstGretR]) {
    //         left[firstGretL] -= min(left[firstGretL], right[firstGretR]);
    //         right[firstGretR] -= min(left[firstGretL], right[firstGretR]);
    //         firstGretL ++;
    //         cost += min(left[firstGretL], right[firstGretR]);;
    //     }
    //     else if(left[firstGretL] == right[firstGretR]) {
    //         left[firstGretL] -= min(left[firstGretL], right[firstGretR]);
    //         right[firstGretR] -= min(left[firstGretL], right[firstGretR]);
    //         firstGretL ++;
    //         firstGretR ++;
    //         cost += min(left[firstGretL], right[firstGretR]);;
    //     }
    //     else {
    //         left[firstGretL] -= min(left[firstGretL], right[firstGretR]);
    //         right[firstGretR] -= min(left[firstGretL], right[firstGretR]);
    //         firstGretR ++;
    //         cost += min(left[firstGretL], right[firstGretR]);;   
    //     }
    // }
    // int p1 = firstGretL;
    // int p2 = firstGretR;
    // ll leftCount = 0;
    // ll rightCount = 0;

    // while(firstGretL <= n) {
    //     if(left[firstGretL] > 1) {
    //         if(left[firstGretL]%2 == 0) {
    //             cost += left[firstGretL]/2;
    //             left[firstGretL] = 0;
    //         }
    //         else {
    //             cost += left[firstGretL]/2;
    //             left[firstGretL] = 1;
    //             leftCount++;
    //         }
    //         continue;
    //     }
    //     leftCount++;

    // }
    // while(firstGretR <= n) {
    //     if(right[firstGretR] > 1) {
    //         if(right[firstGretR]%2 == 0) {
    //             cost += right[firstGretR]/2;
    //             right[firstGretR] = 0;
    //         }
    //         else {
    //             cost += right[firstGretR]/2;
    //             right[firstGretR] = 1;
    //             rightCount++;
    //         }
    //         continue;
    //     }
    //     rightCount++;
    // }

    // cost += (leftCount + rightCount);
    // cout<<cost;
}

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}
