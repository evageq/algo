template<typename T>
struct Fenwick3d{
	vector<vector<vector<T>>> s;
	int n,m,z;
	int f(int i) {return i&(i+1);}
	int g(int i) {return i|(i+1);}
	T sum(int x1, int y1, int z1, int x2, int y2, int z2){
		if (x1 > x2){
			swap(x1,x2); swap(y1,y2); swap(z1,z2);
		}
		return
			sum(x2,y2,z2) - sum(x1-1,y2,z2) +
			-sum(x2,y1-1,z2) + sum(x1-1,y1-1,z2) +
			-sum(x2,y2,z1-1) + sum(x1-1,y2,z1-1) +
			sum(x2,y1-1,z1-1) - sum(x1-1,y1-1,z1-1);
	}
	T sum(int posi, int posj, int posk){
		T res = 0;
		for (int i = posi; i >= 0; i = f(i)-1)
			for (int j = posj; j >= 0; j = f(j)-1)
				for (int k = posk; k >= 0; k = f(k)-1)			
					res+=s[i][j][k];
		return res;
	}                                            
	void update(int posi, int posj, int posk, int delta){
		for (int i = posi; i < n; i = g(i))
			for (int j = posj; j < m; j = g(j))
				for (int k = posk; k < z; k = g(k))
					s[i][j][k]+=delta;
	}
	Fenwick3d(vector<vector<vector<T>>> a, int _n, int _m, int _z){
		s = vector<vector<vector<T>>>(_n, vector<vector<T>>(_m,vector<T>(_z,(T)0)));
		n = _n; m = _m; z = _z;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 0; k < z; ++k)
					update(i,j,k,a[i][j][k]);		
	}

};