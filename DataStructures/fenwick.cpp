template<typename T>
struct Fenwick{
	vector<T> s;
	int n;
	int f(int i) {return i&(i+1);}
	int g(int i) {return i|(i+1);}
	T sum(int l, int r){
	    if (l>r) swap(l,r);
		return sum(r)-sum(l-1);
	}
	T sum(int pos){
		T res = 0;
		for (int i = pos; i >= 0; i = f(i)-1)
			res+=s[i];
		return res;
	}
	void update(int pos, T delta){
		for (int i = pos; i < n; i = g(i))
			s[i]+=delta;
	}
	Fenwick(vector<T> a){
		s.resize(a.size(),0);
		n = a.size();
		for (int i = 0; i < n; ++i)
			update(i, a[i]);		
	}
	Fenwick(int n, int _neutral){
		s.resize(n, _neutral);		
	}

};