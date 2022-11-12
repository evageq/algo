struct Heap{
	int size;
	vector<int> nodes;
	const int INF = 2e9;
	Heap(const vector<int>& a){
		size = a.size();
		nodes = a;
		BuildHeap(a);	
	}
	Heap() : size(0) {}
	void BuildHeap(const vector<int>& a){
		for (int i = size/2; i >= 0; --i){
			siftDown(i);
		}
	}
	void siftDown(int i){
		int maxInd = i;
		if (2*i + 1 < size && nodes[maxInd] < nodes[2*i + 1])
			maxInd = 2*i + 1;
		if (2*i + 2 < size && nodes[maxInd] < nodes[2*i + 2])
			maxInd = 2*i + 2;
		if (maxInd != i){
			swap(nodes[i], nodes[maxInd]);
			siftDown(maxInd);
		}
	}
	void siftUp(int i){
		while(i > 0 && nodes[i/2] < nodes[i]){
			swap(nodes[i/2], nodes[i]);
			i /= 2;
		}
	}
	void push(int val){
		nodes.push_back(val);
		size++;
		siftUp(size - 1);
	}
	int top(){
		int ans = nodes[0];
		swap(nodes[size-1], nodes[0]);
		nodes[size-1] = INF;
		size--;
		siftDown(0);
		return ans;
	}
	
};
