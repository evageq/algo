template<typename T>
struct Fenwick2d{
	vector<vector<T>> s;
	int n,m;
	int f(int i) {return i&(i+1);}
	int g(int i) {return i|(i+1);}
	T sum(int x1, int y1, int x2, int y2){
		if (x1>x2){swap(x1,x2); swap(y1,y2);}
		return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
	}
	T sum(int posi, int posj){
		T res = 0;
		for (int i = posi; i >= 0; i = f(i)-1)
			for (int j = posj; j >= 0; j = f(j)-1)			
				res+=s[i][j];
		return res;
	}                                            
	void update(int posi, int posj, int delta){
		for (int i = posi; i < n; i = g(i))
			for (int j = posj; j < m; j = g(j))
			s[i][j]+=delta;
	}
	Fenwick2d(vector<vector<T>> a, int _n, int _m){
		s = vector<vector<T>>(_n, vector<T>(_m,(T)0));
		n = _n; m = _m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				update(i,j,a[i][j]);		
	}

};