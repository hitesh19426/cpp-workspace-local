#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
using namespace std;
void solve();

class quadratic{
public:
	int a;
	int b;
	int max_point;
	ll max_value;
};

bool sortbysec(const quadratic &a, const quadratic &b){
	if (a.max_value!=b.max_value)
		return a.max_value<b.max_value;
	else
		return a.max_point>b.max_point;
}

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve()
{
	int n, B;
	cin>>n>>B;

	quadratic arr[n];
	ll coins=0, profit=0;
	rep(i, n)
	{
		cin>>arr[i].a>>arr[i].b;

		arr[i].max_point = (-1*arr[i].b) / (2*arr[i].a);
		arr[i].max_value = (ll)arr[i].a*arr[i].max_point*arr[i].max_point + (ll)arr[i].b*arr[i].max_point;

		coins += arr[i].max_point;
		profit += arr[i].max_value;
	}

	sort(arr, arr+n, sortbysec);
	
	for (int i=0; i<n;i++)
	{
		if(coins>B)
		{
			coins -= arr[i].max_point;
			profit -= arr[i].max_value;
		}
		else if (coins==B)
		{
			break;
		}
		else
		{
			if (i==0)
			{
				profit=0;
				break;
			}
			else
			{
				ll x=abs(coins-B);
				profit += (ll)arr[i-1].a*x*x + (ll)arr[i-1].b*x;
				break ;
			}
		}
	}

	cout<<profit;

}