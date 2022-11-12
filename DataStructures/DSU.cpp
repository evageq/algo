struct DSU{
	vector<int> par, rank;
	DSU(int n) : par(n), rank(n, 0){
		iota(par.begin(), par.end(), 0);
	}
	int findP(int i){
		return (par[i] == i ? i : (par[i] = findP(par[i])));
	}	
	bool same(int i, int j){
		return findP(i) == findP(j);
	}
	void mergeSets(int i, int j){
		if (same(i, j)) return;
		i = findP(i);
		j = findP(j);
		if (rank[i] < rank[j]){
			par[i] = j;
		}
		else{
		    par[j] = i;
		    if (rank[i] == rank[j])
		    	rank[i]++;
		}	

	}

};
