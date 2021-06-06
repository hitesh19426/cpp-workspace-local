class max_heap
{
	int size;
	vector<int> heap;

	int parent(int i) { return (i-1)/2; }
	int left(int i) { return 2*i+1; }
	int right(int i) { return 2*i+2; }

	void rev_heapify(int ind)
	{
		if(ind==0)
			return ;

		int p = parent(ind);
		if(heap[p].second>=heap[ind].second)
			return ;

		swap(heap[p], heap[ind]);
		rev_heapify(p);
	}

	void heapify(long long ind)
	{
		int max = ind;
		int l = left(ind), r = right(ind);
		
		if( l<size && heap[l].second>heap[max].second)
			max = l;
		if( r<size && heap[r].second>heap[max].second)
			max = r;
		if( max == ind)
			return ;
		
		swap( heap[ind], heap[max]);
		heapify(max);	
	}

public:
	max_heap(int n)
	{
		size = 0;
		heap.reserve(n);
	}

	void insert(long long val)
	{
		heap.emplace_back(val);
		size++;
		rev_heapify(size-1);
	}

	int getMax()
	{
		if(size==0)
			return -1;
		return heap[0].first;
	}

	void removeMax()
	{
		if(size==0)
			return ;

		size--;
		swap(heap[0], heap[size]);
		heapify(0);
	}

	bool empty()
	{
		if(size==0)
			return true;
		return false;
	}

};

