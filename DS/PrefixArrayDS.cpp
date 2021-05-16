#include <bits/stdc++.h>
using namespace std;

template<class T, class Q>
class PrefixArrayDS
{
	vector<Q> pa;
public:
	PrefixArrayDS(vector<T> _v)
	{
		pa.resize(_v.size());
		for (unsigned int i=0; i < _v.size(); i++)
		{
			pa[i] = i==0 ? _v[i] : pa[i-1] + _v[i];
		}
	}

	Q query(int l, int r)
	{
		if (l==0)
			return pa[r];
		return pa[r] - pa[l-1];
	}

};

int main()
{
	std::vector<long long> v = {14, 7,  1, 5, 10};

	PrefixArrayDS<long long, long long> obj(v);

	cout<<obj.query(2, 4);

	return 0;
}

