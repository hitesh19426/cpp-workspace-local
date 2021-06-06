template <class T>
class queue
{
	stack<T> st, q;
	void transfer(){
		while(!st.empty()){
			T x = st.top();
			st.pop();
			q.push(x);
		}
	}
public:
	queue();
	
	void push(T x){
		st.push(x);
	}

	void pop(){
		if(!q.empty()){
			q.pop();
		}
		transfer();
		q.pop();
	}

	int front(){
		if(!q.empty()){
			return q.top();
			return;
		}
		transfer();
		return q.top();

	}
};