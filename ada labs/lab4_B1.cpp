#define rep(i, n)	for (int i=0;i<n;i++)
#define reps(i, a, n)	for (int i=a;i<n;i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define inf_ll 1000000000000000000
#define inf 1000000000
#define endl '\n'
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define gcd(a, b)	__gcd(a, b)
#define lcm(a, b)	(a/gcd(a, b))*b
#define maxt(a, b, c) max(a, max(b, c))
#define mint(a, b, c) min(a, min(b, c))
using namespace std;
void solve();

int main(int argc, char const *argv[])
{
	/* code */
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n, e, k;
	cin>>n>>e>>k;

	vector<vector<int, int>> graph(n);
	rep(i, n)
	{
		graph.pb(vii);
	}

	rep(i, e)
	{
		int vi, vj, wij;
		cin>>vi>>vj>>wij;

		graph[vi].pb(make_pair(vj, wij));
		graph[vj].pb(make_pair(vi, wij));
	}

	
	bool visited[n]; int src=0; ll dist[n];
	rep(i, n)	visited[i]=false;
	rep(i, n)	dist[i]=inf_ll
	dist[src]=0;
	visited[src]=true;


	priority_queue<ll> q;
	
	while (q.empty()==false){
		auto ver=q.top();
		q.pop();

		for (auto itr=graph[ver].begin(); itr!=graph[ver].end(); itr++)
		{

		}
	}


}

