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

	int t;
	cin >> t;
	
	while (t--){
		int n,e,q,r;
		cin >> n >> e >> q >> r;
		
		vector<vector<int>> graf(n+1);
		vector<pii> edge;
		edge.pb(mp(0,0));
		
		for (int i = 0; i < e; i++){
			int a, b;
			cin >> a >> b;
			
			edge.pb(mp(a,b));
			graf[a].pb(b);
			graf[b].pb(a);
		}
		
		vector<bool> nodekhusus(n+1, false);
		for (int i = 0; i < q; i++){
			int x;
			cin >> x;
			
			nodekhusus[x] = true;
		}
		
		int ans = 0;
		vector<bool> vis(n+1, false);
		
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			
			stack<int> s;
			int cnt = 0;
			s.push(i);
			vis[i] = true;
			
			while (!s.empty()){
				int x = s.top(); s.pop();
				
				vis[x] = true;
				if (nodekhusus[x]) cnt++;
				
				int sz = graf[x].size();
				for (int j = 0; j < sz; j++){
					int k = graf[x][j];
//					cout << "edge: " << x << " " << k << endl;
					if (vis[k]) continue;
					vis[k] = true;
					s.push(k);
				}
			}
			
			ans += (cnt*(cnt-1)/2);
		}
		
		vector<bool> hapus(e+1, false);
		for (int i = 0; i < r; i++){
			int x;
			cin >> x;
			
			hapus[x] = true;
		}
//		cout << "ok";
		for (int i = 1; i <= n; i++) graf[i].clear();
		for (int i = 1; i <= e; i++){
			if (!hapus[i]){
				int a = edge[i].fi;
				int b = edge[i].se;
				
				graf[a].pb(b);
				graf[b].pb(a);
			}
		}
		
//		cout << " ok";
		fill(vis.begin(), vis.end(), false);
		int ans2 = 0;
		
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			
			int cnt = 0;
			stack<int> s;
			s.push(i);
			vis[i] = true;
			
			while (!s.empty()){
				int x = s.top(); s.pop();
				
				if (nodekhusus[x]) cnt++;
				
				int sz = graf[x].size();
				for (int j = 0; j < sz; j++){
					int k = graf[x][j];
					if (vis[k]) continue;
//					cout << "edge: " << x << " " << k << endl;
					vis[k] = true;
					s.push(k);
				}
			}
			
			ans2 += (cnt*(cnt-1)/2);
		}
		
//		cout << ans << " " << ans2 << endl;
		cout << ans - ans2 << "\n";
	}

	return 0;
}
