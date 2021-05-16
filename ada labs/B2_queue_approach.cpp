#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
using namespace std;
void solve();
// void showheap(priority_queue<quadratic, vector<quadratic> , comparator> max_heap);

struct quadratic
{
	ll a;
	ll b;
	//int maxima_point;
	//ll maxima;
	ll current_x;
	ll gain;
};

struct comparator
{
	bool operator()(quadratic const& q1, quadratic const& q2)
	{
		return q1.gain < q2.gain;
	}
};


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

void showheap(priority_queue<quadratic, vector<quadratic> , comparator> max_heap)
{
	cout<<"queue/max_heap: "<<endl;
	while (max_heap.empty()==false)
	{
		auto curr=max_heap.top();
		cout<<curr.a<<" "<<curr.b<<" "<<curr.current_x<<" "<<curr.gain<<endl;
		max_heap.pop();
	}
	cout<<endl;
}

void solve()
{
	ll n, k;
	cin>>n>>k;

	quadratic arr[n];
	rep(i, n){
		cin>>arr[i].a>>arr[i].b;

		//arr[i].maxima_point = (-1*arr[i].b)/(2*arr[i].a);
		//arr[i].maxima = arr[i].a*arr[i].maxima_point*arr[i].maxima_point + arr[i].b*arr[i].maxima_point;
		arr[i].current_x = 0;
		arr[i].gain = arr[i].a + arr[i].b;
	}

	priority_queue<quadratic, vector<quadratic> , comparator> max_heap;

	//showheap(max_heap);

	rep(i, n)
	{
		if (arr[i].gain > 0)
			max_heap.push(arr[i]);
	}

	//showheap(max_heap);

	ll coin_used=0;
	ll profit=0;

	while ( (coin_used<k) && (max_heap.empty()==false) )
	{
		// showheap(max_heap);

		auto max_ele = max_heap.top();
		max_heap.pop();

		// cout<<"max element values: ";
		// cout<<max_ele.a<<" "<<max_ele.b<<" "<<max_ele.current_x<<" "<<max_ele.gain<<endl;

		coin_used++;
		profit += max_ele.gain;
		
		// cout<<max_ele.a<<" "<<max_ele.b<<" "<<max_ele.current_x<<endl;
		max_ele.current_x++;
		max_ele.gain = 2*(max_ele.a)*(max_ele.current_x) + max_ele.a + max_ele.b;
		
		// cout<<"max element values: ";
		// cout<<max_ele.a<<" "<<max_ele.b<<" "<<max_ele.current_x<<" "<<max_ele.gain<<endl;

		if (max_ele.gain > 0)
		{
			max_heap.push(max_ele);
		}

		//showheap(max_heap);
	}

	cout<<profit;
}