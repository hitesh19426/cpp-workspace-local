//
// Created by hitesh on 12/02/21.
//
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;

int main()
{

    ll n, q, k;
    cin>>n>>q>>k;

    ll arr[n];
    rep(i, n)   cin>>arr[i];

    if (n==1)
    {
        while (q--) {
            ll l, r;
            cin >> l >> r;
            ll x = arr[l - 1], y = arr[r - 1];
            ll moves = x - 1 + k - y;
            cout << moves << endl;
        }
    }
    else
    {
        long long D[n-1];
        D[0]=arr[1]-arr[0]-1;
        for(int i=1;i<n-1;i++)
        {
            D[i] = D[i-1] + arr[i+1]-arr[i]-1;
        }

//        rep(i, n-1) cout<<D[i]<<" ";
//        cout<<endl;

        while (q--) {
            ll l, r;
            cin >> l >> r;
            l -= 1, r-=1;

            ll x = arr[l], y = arr[r];

            long long moves = x - 1 + k - y;
            if (l==0){
                moves += 2*D[r-1];
            }
            else {
                moves += 2 * (D[r-1] - D[l-1]);
            }
            cout << moves << endl;
        }

    }

    return 0;
}