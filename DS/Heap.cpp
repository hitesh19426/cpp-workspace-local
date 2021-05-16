#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vll vector<long long>
#define vvi vector<vector<int>>

#define endl '\n'
#define nline '\n'
#define inf 1000000000
#define mod 1000000000 + 7
#define inf_ll (ll)1e18
#define PI 3.141592653589793238462

#define pb push_back
#define mp make_pair
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) cout<< #x << " = " << x << endl;
#define printarr(i, arr, n)	for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

void solve();
vll sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*----------------------------------------------------------------------------------------------------*/

class Heap
{
public:
	int size = 0;
	vi heap(); 
	Heap(){
		size = 0;
	}
	Heap(int arr[])
	{
		int n = sizeof(arr)/sizeof(arr[0]);
		for (int i=0;i<n;i++)
		{
			insert(arr[i]);
		}
	}
	Heap(vi arr)
	{
		int n = arr.size();
		for (int i=0;i<n;i++)
		{
			insert(arr[i]);
		}
	}
	void insert(int x)
	{
		if (heap.size()>=size)
			heap[size] = x;
		else
			heap.pb(x);

		size++;
		rev_heapify(size-1);
	}
	int front()
	{
		if (size == 0)
			return -1;
		return heap[0];
	}
	void pop()
	{
		if (size == 0)
			return;

		swap(heap[0], heap[size-1]);
		size--;
		heapify(heap[0]);
	}
	void rev_heapify(int ind)
	{
		while (ind != 0 && heap[parent(ind)]>heap[ind])
		{
			swap(heap[ind], heap[parent(ind)]);
			ind = parent(ind);
		}
	}
	void heapify(int ind)
	{
		
		
		int min = ind, left = left(ind), right = right(ind);

		if (left<size && heap[left]<heap[min])
			min = left;

		if (right<size && heap[right]<heap[min])
			min = right;

		if (min == ind) return ;
		swap(heap[ind], heap[min]);

		heapify(min);
	}
	void decrease_key(int ind, int val)
	{
		if (val<0 || ind<0 ||| ind>=size) return ;

		heap[ind] -= val;
		rev_heapify(ind);
	}
	void increase_key(int ind, int val)
	{
		if (val<0 || ind<0 ||| ind>=size) return ;
	
		heap[ind] += val;
		heapify(ind);
	}

	int left(int x)
	{
		return 2*x+1;
	}
	int right(int x)
	{
		return 2*x+2;
	}
	int parent(int x)
	{
		return (x-1)/2;
	}

	~Heap();	
};

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
	int t=1;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	
}

