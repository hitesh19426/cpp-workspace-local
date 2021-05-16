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

ll first_greater(ll arr[], ll n, ll x, ll l, ll r)
{
    if (r<l)
        return n;

    ll mid = l + (r-l)/2;
    ll ans=n;
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

    ll n, l, r;
    cin>>n>>l>>r;

    ll left[n+5];
    ll right[n+5];

    n += 4;

    for (ll i=0;i<=n;i++)
    {
        left[i] = 0;
        right[i] = 0;
    }

    loops(i, 0, l) {
        ll x;
        cin>>x;
        left[x]++;
    }
    loops(i, 0, r) {
        ll x;
        cin>>x;
        right[x]++;
    }


    loops(i, 0, n+1) 
    {
        if(left[i] > 0  && right[i] > 0)
        {
            ll mini = min(left[i], right[i]);
            left[i] -= mini;
            right[i] -= mini;
        }
    }

    sort(left, left+n+1);
    sort(right, right+n+1);
    ll firstGretL = first_greater(left, n+1, 1, 0, n);
    ll firstGretR = first_greater(right, n+1, 1, 0, n);

    // for (ll i=firstGretL;i<=n;i++)
    //     cout<<left[i]<<" ";
    // cout<<endl;

    // for (ll i=firstGretR;i<=n;i++)
    //     cout<<right[i]<<" ";
    // cout<<endl;

    ll cost = 0;
    ll leftCount = 0;
    ll rightCount = 0;

    ll p1 = firstGretL;
    ll p2 = firstGretR;
    while(p1 <= n && p2 <= n) 
    {
        if (left[p1]%2==0 || right[p2]%2==0)
        {
            if (left[p1]%2==0)
                p1++;
            if (right[p2]%2==0)
                p2++;
            continue;
        }

        left[p1] -= 1;
        right[p2] -= 1;
        cost += 1;
        p1++; p2++;
    }

    sort(left, left+n+1);
    sort(right, right+n+1);
    firstGretL = first_greater(left, n+1, 1, 0, n);
    firstGretR = first_greater(right, n+1, 1, 0, n);


    ll ptr1=firstGretL;
    ll ptr2=firstGretR;
    while(ptr1 <= n && ptr2 <= n) 
    {
        ll x = min(left[ptr1], right[ptr2]);
        left[ptr1] -= x;
        right[ptr2] -= x;
        cost += x;

        if(left[ptr1] < right[ptr2]) {
            ptr1++;
        }
        else if(left[ptr1] == right[ptr2] && left[ptr1]==1) {
            ptr1++; ptr2++;
        }
        else {
            ptr2++;
        }
    }

    // print(cost);
    // for (ll i=firstGretL;i<=n;i++)
    //     cout<<left[i]<<" ";
    // cout<<endl;

    // for (ll i=firstGretR;i<=n;i++)
    //     cout<<right[i]<<" ";
    // cout<<endl;


    for (ll i=firstGretL;i<=n;i++)
    {
        if (left[i]==1)
        {
            leftCount++;
            continue;
        }

        if(left[i] > 1) 
        {
            if(left[i]%2 == 0) {
                cost += left[i]/2;
                left[i] = 0;
            }
            else {
                cost += left[i]/2;
                left[i] = 1;
                leftCount++;
            }
        }
    }
    for (ll i=firstGretR;i<=n;i++) 
    {
        if (right[i]==1)
        {
            rightCount++;
            continue;
        }

        if(right[i] > 1) 
        {
            if(right[i]%2 == 0) {
                cost += right[i]/2;
                right[i] = 0;
            }
            else {
                cost += right[i]/2;
                right[i] = 1;
                rightCount++;
            }
        }
    }

    cost += leftCount + rightCount;
    cout<<cost;
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
