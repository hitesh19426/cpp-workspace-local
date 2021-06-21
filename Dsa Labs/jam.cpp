#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int m, n;
    cin>>m>>n;

    unsigned long long int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    if( m < n )
    {
        int query;
        cin >> query;
        
        while(query--)
        {
            unsigned long long int target;
            cin >> target;
            int ans = -1, i=0;

            for( i=0; i<m; i++)
            {
                int low = 0, high = n-1;
                while( low <= high ){
                    int mid = low + (high-low)/2;
                    if(arr[i][mid] == target)
                    {
                        // cout << i+1 << " " << mid+1 << "\n";
                        ans = mid+1;
                        break;
                    }
                    else if(arr[i][mid] < target)
                        low = mid+1;
                    else
                        high = mid-1;
                }
                if(ans != -1 && low<=high) break;
            }
            if(ans == -1) cout << -1 << "\n";
            else cout << i+1 << " " << ans+1 << "\n";
        }
    }
    else
    {
        int query;
        cin >> query;
        
        while( query-- )
        {
            unsigned long long int target;
            cin >> target;
            int ans = -1, i=0;

            for( i=0; i<n; i++)
            {
                int low = 0, high = m-1;
                while(low <= high){
                    int mid = low + (high-low)/2;
                    if(arr[mid][i] == target)
                    {
                        // cout << mid+1 << " " << i+1 << "\n";
                        ans = mid;
                        break;
                    }
                    else if(arr[i][mid] < target)
                        low = mid+1;
                    else
                        high = mid-1;
                }
                if(ans != -1 && low<=high) break;
            }
            if(ans == -1) cout << -1 << "\n";
            else cout << i+1 << " " << ans+1 << "\n";
        }
        
    }

	
}
