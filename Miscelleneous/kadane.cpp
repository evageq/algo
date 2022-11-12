pair<int64_t, pair<int, int>> kadane(vector<int> a){ //cost, (l, r)
	const int INF = 2e9;
	pair<int64_t, pair<int, int>> ans;
	vector<pair<int, int64_t> > dp(a.size()); dp[0]={0,a[0]}; //l, cost
	for (int i = 1; i < a.size(); ++i){
		if (dp[i-1].second+a[i]>a[i]){
			dp[i].first=dp[i-1].first;
			dp[i].second=dp[i-1].second+a[i];			
		}
		else{
		    dp[i].first = i;
		    dp[i].second=a[i];
		}	
	}
	int64_t mx = -INF;
	for (int i = 0; i < a.size(); ++i){
		if (dp[i].second>mx){
			mx=dp[i].second;
			ans={mx, {dp[i].first, i}};
		}
	}	
	return ans;
	
}