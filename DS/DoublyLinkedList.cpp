#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

#define pb push_back
#define mp make_pair
#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define foreach(itr, v) for (auto itr=v.begin();itr!=v.end();itr++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve();

#ifndef ONLINE_JUDGE
#define print(x) cerr<< #x << " = "; _print(x); cerr<<endl;
#else
#define print(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

/*----------------------------------------------------------------------------------------------------*/

template<class T>
class doubly_linked_list
{
	class node
	{
	public:
		T val;
		node *left;
		node *right;
		node(){
			val = 0;
			right = left = NULL;
		}
	};

	node *head;
	node *tail;
	int size;

public:
	doubly_linked_list()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	node* create_node(T x){
		node *temp = new node();
		(*temp).val = x;
		return temp;
	}
 
	void push_back(T x)
	{
		if (size == 0){
			node* temp = create_node(x);
			head = tail = temp;

			(*tail).left = head;
			(*head).right = tail;

			size++;
			return ;
		}

		node *temp = create_node(x);
		
		(*tail).right = temp;
		(*temp).left = tail;

		tail = temp;
		size++;
	}

	void push_front(T x)
	{
		if (size == 0){
			node* temp = create_node(x);
			head = tail = temp;

			(*tail).left = head;
			(*head).right = tail;

			size++;
			return;
		}

		node *temp = create_node(x);

		(*temp).right = head;
		(*head).left = temp;

		head = temp;
		size++;
		return;
	}

	T front(){
		if (size==0)
			return no_value();

		return (*head).val;
	}

	T back(){
		if (size==0)
			return no_value();

		return (*tail).val;
	}

	T no_value(){
		return -1;
	}

	void pop_front(){
		if (size == 0)
			return;

		head = (*head).right;
		size--;
	}

	void pop_back()
	{
		if (size==0)
			return;

		tail = (*tail).left;
		size--;
	}

	void print_list()
	{
		node *ptr = head;
		while (ptr != tail)
		{
			cout<< (*ptr).val <<" ";
			ptr = (*ptr).right;
		}
		cout<< (*ptr).val <<endl;
	}

	void print_list_reverse()
	{
		node *ptr = tail;
		while (ptr != head)
		{
			cout<< (*ptr).val <<" ";
			ptr = (*ptr).left;
		}
		cout<< (*ptr).val <<endl;
	}
	
};

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
		// cout<<endl;
	}
	return 0;
}

void solve(){
	int arr[] = {1, 2, 3, 5, 7, 10, 1};

	doubly_linked_list<int> list;

	for (const auto &x:arr)
		list.push_back(x);

	list.print_list();
	list.print_list_reverse();
}

