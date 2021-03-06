#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	/* code */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("errorf.in", "w", stderr);
#endif

	int t = 1;
	// cin>>t;
	while (t--)
	{
		solve();
		cout << endl;
	}
	return 0;
}

struct trieNode
{
	trieNode *children[26];
	bool endOfWord;

	trieNode()
	{
		for (int i = 0; i < 26; i++)
			children[i] = nullptr;
		endOfWord = false;
	}
};

void insert(trieNode *root, string key)
{
	trieNode *ptr = root;
	for (int i = 0; i < (int)key.size(); i++)
	{
		int ind = key[i] - 'a';

		if (ptr->children[ind] == nullptr)
		{
			ptr->children[ind] = new trieNode();
		}

		ptr = ptr->children[ind];
	}

	ptr->endOfWord = true;
}

bool search(trieNode *root, string str)
{
	trieNode *ptr = root;
	int i, n = str.size();
	for (i = 0; i < n; i++)
	{
		int ind = str[i] - 'a';
		if (ptr->children[ind] == nullptr)
			return false;

		ptr = ptr->children[ind];
	}

	return ptr->endOfWord;
}

void solve()
{
	vector<string> arr{"the", "a", "there", "answer", "any", "by", "bye", "their"};

	trieNode *root = new trieNode();

	for (string str : arr)
		insert(root, str);

	search(root, "there") ? cout << "YES\n" : cout << "NO\n";
	search(root, "these") ? cout << "YES\n" : cout << "NO\n";
}
