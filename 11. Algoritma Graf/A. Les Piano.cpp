#include <bits/stdc++.h>

using namespace std;

int main(){

	int v, e, a, b;
	cin >> v >> e >> a >> b;
	
	vector<vector<pair<int, int>>> graf(v+1);
	
	for (int i = 0; i < e; i++){
		int x, y, z;
		cin >> x >> y >> z;
		
		graf[x].push_back(make_pair(y,z));
		graf[y].push_back(make_pair(x,z));
	}
	
	vector<int> val(v+1, INT_MAX);
	
	queue<int> s;
	s.push(a);
	val[a] = 0;
	
	while(!s.empty()){
		int x = s.front(); s.pop();
		int sz = graf[x].size();
		for (int i = 0; i < sz; i++){
			int k = graf[x][i].second;
			if (k+val[x] < val[graf[x][i].first]){
				val[graf[x][i].first] = k+val[x];
				s.push(graf[x][i].first);
			}
			
		}
	}
	
	cout << val[b] << endl;

	return 0;
}
