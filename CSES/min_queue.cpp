#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t=1;
	cin>>t;

	stack<pair<int, int>> st1, st2;

	while(t--){
		int query, x;
		cin>>query;

		if(query==1){
			cin>>x;
			if(st1.empty())
				st1.push({x, x});
			else
				st1.push({x, min(x, st1.top().second)});
		}
		else if(query==2){
			if(st2.empty() && st1.empty()){
				cout<<-1<<endl;
			}
			else{
				if(st2.empty()){
					while(!st1.empty()){
						if(st2.empty())
							st2.push({st1.top().first, st1.top().first});
						else{
							int key = st1.top().first;
							int val = min(key, st2.top().second);
							st2.push({key, val});
						}
						st1.pop();
					}
				}

				int front = st2.top().first;
				st2.pop();
				cout<<front<<endl;
			}
		}
		else if(query==3){
			if(st1.empty() && st2.empty()){
				cout<<-1<<endl;
			}
			else{
				if(st2.empty()){
					while(!st1.empty()){
						if(st2.empty())
							st2.push({st1.top().first, st1.top().first});
						else{
							int key = st1.top().first;
							int val = min(key, st2.top().second);
							st2.push({key, val});
						}
						st1.pop();
					}
				}

				int front = st2.top().first;
				cout<<front<<endl;
			}
		}
		else{

			if(st1.empty() && st2.empty()){
				cout<<-1<<endl;
				continue;
			}

			if(st2.empty()){
				while(!st1.empty()){
					if(st2.empty())
						st2.push({st1.top().first, st1.top().first});
					else{
						int key = st1.top().first;
						int min_element = min(key, st2.top().second);
						st2.push({key, min_element});
					}
					st1.pop();
				}
			}

			int front = st2.top().second;
			int st1_min = (st1.empty() ? INT_MAX : st1.top().second);
			cout<<min(front, st1_min)<<endl;
		}

	}

	return 0;
}
