#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	
	while (t--){
		int v, e; cin >> v >> e;
		
		vector<vector<pii>> graf(v);
		
		for (int i = 0 ; i < e; i++){
			int a, b, c;
			cin >> a >> b >> c;
			graf[a].pb(mp(b,c));
		}
		
		vector<int> vis(v, 0);
		vis[0] = 1;
		vector<int> val(v, 1e15);
		val[0] = 0;
		priority_queue<pii, vector<pii>, greater<pii>> q;
		q.push(mp(0,0));
		bool ok = true;
		
		while (!q.empty()){
			int x = q.top().se;
			int valx = q.top().fi;
			q.pop();
			
			for (int i = 0; i < graf[x].size(); i++){
				int k = graf[x][i].fi;
				int weight = graf[x][i].se;
				int cmpval = weight + valx;
				if (vis[k] >= v){
					ok = false;
					break;
				}
				else if (cmpval < val[k]){
					vis[k]++;
					val[k] = cmpval;
					q.push(mp(val[k], k));
				}
			}
			if (!ok) break;
		}
		
		if (!ok) cout << "Pak Dengklek tidak mau pulang\n";
		else if (!vis[v-1]) cout << "Tidak ada jalan\n";
		else cout << val[v-1] << "\n";
	
	}
	
	
	return 0;
}
