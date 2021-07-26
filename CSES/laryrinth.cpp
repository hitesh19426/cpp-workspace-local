#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define pii pair<int, int>
#define vvb vector<vector<bool>>
#define vpii vector<pii>
#define vi vector<int>
#define ff first
#define ss second

/*----------------------------------------------------------------------------------------------------*/

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
		cout<<endl;
	}
	return 0;
}

void solve(){
	int n, m;
	cin>>n>>m;

	string arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	pii start, end;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 'A')
				start = {i, j};
			else if(arr[i][j] == 'B')
				end = {i, j};
		}
	}
	vi xd {-1, 1, 0, 0};
	vi yd {0, 0, -1, 1};
	
	vvb vis(n, vector<bool>(m, false));
	vector<vpii> parent(n, vector<pii>(m));
	
	queue<pii> q;
	q.push( start );
	vis[start.first][start.second] = true;
	parent[start.first][start.ss] = {-1, -1};

	while(!q.empty()){
		auto pt = q.front();
		q.pop();

		if(pt == end)
			break;

		for(int i=0; i<4; i++){
			int xnew = pt.first + xd[i];
			int ynew = pt.second + yd[i];

			if(xnew>=0 && xnew<n && ynew>=0 && ynew<m){
				if(arr[xnew][ynew] != '#' && !vis[xnew][ynew]){
					q.push( {xnew, ynew} );
					vis[xnew][ynew] = true;
					parent[xnew][ynew] = pt;
				}
			}
		}
	}

	if(!vis[end.ff][end.ss]){
		cout << "NO";
		return ;
	}
	
	string dir = "UDLR";
	auto cur = end;
	string path = "";

	while( cur != start ){
		
		if(parent[cur.ff][cur.ss].ff-1 == cur.ff){
			path += 'U';
		}
		else if(parent[cur.ff][cur.ss].ff+1 == cur.ff){
			path += 'D';
		}
		else if(parent[cur.ff][cur.ss].ss-1 == cur.ss){
			path += 'L';
		}
		else if(parent[cur.ff][cur.ss].ss+1 == cur.ss){
			path += 'R';
		}

		cur = parent[cur.ff][cur.ss];
	}

	reverse(path.begin(), path.end());
	cout << "YES\n";
	cout << path.size() << "\n";
	cout << path;

}
