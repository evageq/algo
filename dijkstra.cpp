vector<int64_t> dijkstra(vector<vector<pair<int64_t, int> > >& g, int s){
    const int64_t inf = 1e18;
	priority_queue<pair<int64_t, int>, vector<pair<int64_t, int> >, greater<pair<int64_t, int> > > q;
	vector<int64_t> d(g.size(),inf);
	vector<bool> used(g.size(), 0);
	q.push({0,s}); d[s]=0;

	while(q.empty()==false){
		auto v = q.top();
		q.pop();
		if (used[v.second]) continue;
		used[v.second]=1;
		for (auto u : g[v.second]){
			if (d[v.second]+u.first<d[u.second]){
				d[u.second]=d[v.second]+u.first;
				q.push({d[u.second], u.second});
			}
		}
	}
	return d;
}
