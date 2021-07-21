#include <bits/stdc++.h>
using namespace std;
void solve();

#define endl '\n'
#define mod 1000000007
#define fastio()                     \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

//----------------------------------------------------------------------------------------------------//

int main(int argc, char const *argv[])
{
	/* code */
	fastio();
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
	unordered_map<char, trieNode *> children;
	bool endOfWord;

	trieNode() : endOfWord(false) {}
};

void insert(trieNode *root, string str)
{
	trieNode *ptr = root;
	for (char ch : str)
	{
		if (ptr->children.find(ch) == ptr->children.end())
			ptr->children[ch] = new trieNode();

		ptr = ptr->children[ch];
	}

	ptr->endOfWord = true;
}

bool search(trieNode *root, string str)
{
	trieNode *ptr = root;
	for (char ch : str)
	{
		if (ptr->children.find(ch) == ptr->children.end())
			return false;

		ptr = ptr->children[ch];
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
