class stack_min {
	stack<pair<int, int>> st;

	void push(int x){
		if(st.empty()){
			st.push_back({x, x});
			return;
		}
		int new_min = min(x, st.back().second);
		st.push({x, new_min});
	}

	void pop(){
		st.pop();
	}

	int min(){
		return st.top().second;
	}

}